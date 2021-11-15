#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> visited, sequence, result;

bool cmp(const int &i1, const int &i2) {
    return sequence[i1] < sequence[i2];
}

//재귀함수로 dfs 수행
void dfs(int cur, vector<vector<int>> &graph) {
    visited[cur] = true;
    result.push_back(cur);
    for (int i = 0; i < graph[cur].size(); i++) {
        if (!visited[graph[cur][i]])
            dfs(graph[cur][i], graph);
    }
}

//입력받은 순서와 dfs 결과 비교
bool isDfs(vector<int> &route) {
    for (int i = 0; i < route.size(); i++) {
        if (route[i] != result[i])
            return false;
    }
    return true;
}

/**
 *  예제 입력 3  -> 예제 입력 3
 *  1 | 2 3        1 | 3 2
 *  2 | 1 4        2 | 1 4
 *  3 | 1          3 | 1
 *  4 | 2          4 | 2
 *
 *  route : 1 3 2 4
 *
 *  알 수 있는 것
 *  1. 1번 정점은 3, 2, 4번 정점보다 먼저 탐색된다.
 *  2. 3번 정점은 2, 4번 정점보다 먼저 탐색된다.
 *  3. 2번 정점은 4번 정점보다 먼저 탐색된다.
 *  -> 정점 i, j의 위치를 x, y라고 할 때, x < y면 정점 i는 정점 j보다 먼저 탐색해야 함
 *  -> 위치 관계를 기준으로 정렬
 *
 *  정렬 후 dfs 탐색을 한 결과가 입력된 경로와 같다면 올바른 방문 순서
 */
int main() {
    int n, a, b;

    //입력
    cin >> n;
    vector<vector<int>> graph(n + 1, vector<int>(0));
    vector<int> route(n, 0);
    visited.assign(n + 1, 0);
    sequence.assign(n + 1, 0);

    for (int i = 1; i < n; i++) { //무방향 그래프
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < n; i++) { //각 정점의 순서 인덱스를 sequence 배열에 저장
        cin >> route[i];
        sequence[route[i]] = i;
    }

    //연산
    for (int i = 1; i <= n; i++) //sequence 기준 오름차순 정렬
        sort(graph[i].begin(), graph[i].end(), cmp);
    dfs(1, graph);

    //출력
    cout << isDfs(route);
}