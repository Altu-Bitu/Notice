#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int INF = 1e9;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

struct status { //행, 열, 방향, 비용
    int r, c, dir, cost;
};

int bfs(int n, vector<vector<int>> board) {
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(n, vector<int>(4, INF)));
    queue<status> q;

    //시작점 초기화 (시작점은 모든 방향일 수 있음)
    for (int i = 0; i < 4; i++) {
        dist[0][0][i] = 0;
        q.push({0, 0, i, 0});
    }

    while (!q.empty()) {
        int row = q.front().r;
        int col = q.front().c;
        int dir = q.front().dir;
        int cost = q.front().cost;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || board[nr][nc])
                continue;
            int nw = i == dir ? cost + 100 : cost + 600; //방향에 따른 비용
            if (nw < dist[nr][nc][i]) { //더 적은 비용으로 경주로를 건설할 수 있다면
                dist[nr][nc][i] = nw;
                q.push({nr, nc, i, nw});
            }
        }
    }
    int min_cost = INF;
    for (int i = 0; i < 4; i++) //4개의 방향 중 가장 작은 값
        min_cost = min(min_cost, dist[n - 1][n - 1][i]);
    return min_cost;
}

int solution(vector<vector<int>> board) {
    return bfs(board.size(), board);
}

/**
 * 하나의 좌표에 대해 자동차는 4개의 방향을 통해 진입할 수 있음.
 * (행, 열) 정보만 저장했던 기존의 방식과 달리 (행, 열, 방향) 정보까지 저장! -> 3차원 배열
 * 배열에 저장되는 값은 해당 좌표와 방향으로 건설할 수 있는 경주로 중 가장 비용이 저렴한 것
 * !주의! 시작점은 방향이 따로 없으므로 초기화시 모든 방향에 대해 정보를 입력함
 *
 * 방향에 따른 비용에 차이를 두며 구현
 * 공식 풀이 : https://tech.kakao.com/2020/07/01/2020-internship-test/
 */
int main() {
    vector<vector<int>> board = {{0, 0, 0},
                                 {0, 0, 0},
                                 {0, 0, 0}};
    cout << solution(board);
}