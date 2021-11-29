#include <iostream>
#include <vector>

using namespace std;

int dp(int n, int m, vector<vector<int>> &board) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i - 1][j - 1]) //현재 위치(i-1, j-1)의 board 값이 1일 경우
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            ans = max(ans, dp[i][j]); //가장 큰 정사각형의 한 변 길이 갱신
        }
    }
    return ans;
}

int solution(vector<vector<int>> board) {
    int n = board.size();
    int m = board[0].size();
    int square_len = dp(n, m, board);
    return square_len * square_len; //가장 큰 정사각형의 넓이 리턴
}

/**
 * dp: 1로 이루어지는 정사각형의 한 변의 길이 저장, 즉 dp[i][j]에는 (i, j)를 끝 점으로 하는 정사각형의 한 변의 길이가 저장됨
 * 점화식: 현재 위치에서 왼쪽, 위쪽, 좌상향 중 가장 작은 정사각형의 한 변 길이 + 1 (단, 현재 위치가 1일 경우)
 *
 * 가장 '작은' 정사각형의 한 변 길이를 가져오는 이유
 * -> 정사각형의 모든 칸이 1로 이루어져있어야 하는데, 가장 큰 값을 가져올 경우 모든 칸이 1이 아닐 수 있기 때문
 * -> 즉, 가장 작은 한 변의 길이 값을 가져오는 경우가 모든 칸이 1인 정사각형을 만드는 경우임
 * ex.        1  0  0        1  0  0
 *            0  1  1   ->   0  1  1
 *            1  1  1        1  1  2
 *             board            dp
 *
 * 해당 풀이는 인덱스 관리를 편하게 하기 위해 dp 배열을 (1, 1)부터 시작 (따라서 현재 board 의 위치를 (i-1, j-1)로 접근)
 */

int main() {
    vector<vector<int>> board = {{0, 1, 1, 1},
                                 {1, 1, 1, 1},
                                 {1, 1, 1, 1},
                                 {0, 0, 1, 0}};
    int ans = solution(board);
    cout << ans;
}