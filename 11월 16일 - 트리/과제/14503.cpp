#include <iostream>
#include <vector>

using namespace std;

int cntCleanRobot(int r, int c, int d, vector<vector<int>> &board) {
    //상, 우, 하, 좌
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    int step = 0, ans = 0;
    while (true) {
        if (board[r][c] == 0) {
            board[r][c] = 2;
            ans++;
        }

        if (step == 4) {
            if (board[r - dr[d]][c - dc[d]] == 1)
                return ans;
            r -= dr[d];
            c -= dc[d];
            step = 0;
        } else {
            d = (d + 3) % 4;
            if (board[r + dr[d]][c + dc[d]]) {
                step++;
                continue;
            }
            r += dr[d];
            c += dc[d];
            step = 0;
        }
    }
}

/**
 * board 정보 -> 0: 빈 칸, 1: 벽, 2: 청소한 공간
 * step: 회전 카운트. 4가 되면 한 바퀴 돌아 다시 제자리로 돌아왔음을 의미
 *
 * 항상 첫 행, 마지막 행, 첫 열, 마지막 열은 벽이라고 문제에서 주어졌으므로 범위 검사를 할 필요가 없음
 */

int main() {
    int n, m, r, c, d;

    //입력
    cin >> n >> m >> r >> c >> d;
    vector<vector<int>> board(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    //연산 & 출력
    cout << cntCleanRobot(r, c, d, board);
    return 0;
}