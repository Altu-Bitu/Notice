#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1e6 + 1;

vector<vector<int>> cost;

int paintDp(int n, int color) {
    vector<vector<int>> dp(n, vector<int>(3, 0));

    //첫번째 집을 칠하는 비용 초기화
    for (int i = 0; i < 3; i++) {
        dp[0][i] = INF;
        if (i == color)
            dp[0][i] = cost[0][i];
    }

    //i번째 집을 각각의 색으로 칠하는 최소 비용
    for (int i = 1; i < n; i++) {
        dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    int ans = INF;
    for (int i = 0; i < 3; i++) {
        if (i != color) //첫번째 집과 n번째 집의 색이 같은 경우 제외
            ans = min(ans, dp[n - 1][i]);
    }
    return ans;
}

/**
 * 1149번 RGB거리의 원형 버전
 *
 * 1번 집의 색과 N번 집의 색이 겹치지 않으려면 1번 집을 무슨 색으로 칠했는지 알아야 함
 * -> 1번 집의 색을 고정하기!
 *
 * 1149번 풀이와 다른 부분 생각해보기
 */
int main() {
    int n;

    //입력
    cin >> n;
    cost.assign(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++)
            cin >> cost[i][j];
    }

    //연산
    int ans = INF;
    for (int i = 0; i < 3; i++) //첫번째 집의 색이 i일 때의 최소 비용
        ans = min(ans, paintDp(n, i));

    //출력
    cout << ans;
}