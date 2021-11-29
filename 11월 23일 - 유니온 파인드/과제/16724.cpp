#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<int>> parent;

//Find 연산
int findParent(int m, int row, int col) {
    if (parent[row][col] < 0) //루트 정점
        return row * m + col;
    int pos = parent[row][col];
    return parent[row][col] = findParent(m, pos / m, pos % m); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
void unionInput(int m, int r1, int c1, int r2, int c2) {
    int xp = findParent(m, r1, c1);
    int yp = findParent(m, r2, c2);
    int xr = xp / m, xc = xp % m;
    int yr = yp / m, yc = yp % m;

    if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
        return;
    if (parent[xr][xc] < parent[yr][yc]) { //새로운 루트 xp
        parent[xr][xc] += parent[yr][yc];
        parent[yr][yc] = xp;
    } else { //새로운 루트 yp
        parent[yr][yc] += parent[xr][xc];
        parent[xr][xc] = yp;
    }
}

void unionPair(int n, int m, vector<vector<char>> &board) {
    map<char, pair<int, int>> dir; //맵을 사용해 각 문자를 방향에 대입
    dir['U'] = {-1, 0};
    dir['D'] = {1, 0};
    dir['L'] = {0, -1};
    dir['R'] = {0, 1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pair<int, int> d = dir[board[i][j]]; //유니온 될 좌표가 있는 방향
            unionInput(m, i, j, i + d.first, j + d.second);
        }
    }
}

int cntZone(int n, int m) {
    int cnt = 0; //집합의 개수 세기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (parent[i][j] < 0)
                cnt++;
        }
    }
    return cnt;
}

/**
 * 1. 화살표를 통해 접근할 수 있는 좌표 = 하나의 집합으로 연결된 좌표
 * 2. 같은 집합 안에 속해있는 좌표들은 모두 언젠가 방문 가능한 좌표
 * 3. 서로소인 각 집합에서 한 개씩의 좌표만 SAFE ZONE이어도 모든 회원들이 안전할 수 있음
 * 4. 2차원 좌표를 int 값 하나로 저장하기 위해 모든 행을 일렬로 나열하는 방법 사용 (각 좌표에 pair 변수를 저장해 부모를 표시할 수도 있음)
 */
int main() {
    int n, m;
    string input;

    //입력
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    parent.assign(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        cin >> input;
        for (int j = 0; j < m; j++)
            board[i][j] = input[j];
    }

    //연산
    unionPair(n, m, board);

    //출력
    cout << cntZone(n, m);
}