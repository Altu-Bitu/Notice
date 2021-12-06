#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> tp;

vector<int> parent;
vector<vector<int>> board;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void dfs(int n, int m, int row, int col, int mark) {
    if (row < 0 || row >= n || col < 0 || col >= m || board[row][col] != 1) //범위를 벗어나거나 탐색할 섬이 아님
        return;

    board[row][col] = mark;
    for (int i = 0; i < 4; i++)
        dfs(n, m, row + dr[i], col + dc[i], mark);
}

int markIsland(int n, int m) {
    int mark = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1) //탐색하지 않은 섬
                dfs(n, m, i, j, ++mark);
        }
    }
    return mark; //(섬의 개수 + 1)
}

void findBridge(int n, int m, int row, int col, int mark, priority_queue<tp, vector<tp>, greater<>> &pq) {
    for (int i = 0; i < 4; i++) {
        int tr = row + dr[i], tc = col + dc[i], dist = 0;
        while (tr >= 0 && tr < n && tc >= 0 && tc < m) {
            if (board[tr][tc]) { //어디든 섬과 닿았다면
                if (board[tr][tc] != mark && dist > 1)
                    pq.push({dist, mark, board[tr][tc]});
                break;
            }
            tr += dr[i];
            tc += dc[i];
            dist++;
        }
    }
}

priority_queue<tp, vector<tp>, greater<>> buildBridge(int n, int m) {
    priority_queue<tp, vector<tp>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j]) //섬이라면
                findBridge(n, m, i, j, board[i][j], pq);
        }
    }
    return pq;
}

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) //값이 음수면 루트 정점
        return node;
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
bool unionInput(int x, int y) {
    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
        return false;
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp];
        parent[yp] = xp;
    } else { //새로운 루트 yp
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
    return true;
}

int kruskal(int v, priority_queue<tp, vector<tp>, greater<>> &pq) {
    int cnt = 0, sum = 0;

    while (!pq.empty() && cnt < v - 1) { //큐에 간선이 있고, 사용한 간선의 수가 v-1보다 적을 동안
        int cost = get<0>(pq.top());
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());

        pq.pop();
        if (unionInput(x, y)) { //유니온 했다면
            cnt++; //사용된 간선 증가
            sum += cost; //간선의 가중치
        }
    }
    if (cnt < v - 1) //섬을 연결할 수 없음
        return -1;
    return sum;
}

/**
 * 1. 각각의 섬을 구분 짓기
 * 2. 임의의 두 섬에 대한 다리(간선) 모두 구하기
 * 3. 다리들에 대해 MST 알고리즘 수행
 * 입력 범위가 작기 때문에 가능한 다리를 구하는 과정에서 브루트포스하게 접근해도 됨
 *
 * 1. DFS(BFS 가능)로 모든 섬을 탐색하며 구분 짓기 : markIsland, dfs 함수 (DFS & BFS 과제 4963번 : 섬의 개수 참고)
 * 2. 브루트포스로 두 섬에 대한 가능한 모든 다리 구하기 : findBridge, buildBridge 함수
 *    섬의 형태가 ㄷ 모양이라면 다리를 건설하다가 자기 자신과 닿을 수 있으므로 주의!
 * 3. 모든 다리들에 대해 MST 알고리즘을 수행하지만, MST를 만들 수 없는 경우가 있음
 *
 * 풀이 : https://myunji.tistory.com/373
 * *그냥 리팩토링 전후 비교용으로 보세요!
 */
int main() {
    int n, m;

    //입력
    cin >> n >> m;
    board.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    //연산
    int node = markIsland(n, m);
    parent.assign(node + 1, -1);
    priority_queue<tp, vector<tp>, greater<>> pq = buildBridge(n, m);

    //출력
    cout << kruskal(node - 1, pq);
}