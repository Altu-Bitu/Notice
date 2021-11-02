#include <iostream>
#include <vector>

using namespace std;

int easyStairNum(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(12, 0));
    int ans = 0;

    //1의 자리 쉬운 계단 수 먼저 초기화.
    for (int i = 2; i <= 10; i++) //i: 끝나는 수 (1 ~ 9)
        dp[1][i] = 1;

    //자릿수마다 j로 끝나는 쉬운 계단 수의 개수 구하기
    for (int i = 2; i <= n; i++) { //i: 자릿수
        for (int j = 1; j <= 10; j++) { //j: 끝나는 수 (0 ~ 9)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }
    }

    for (int i = 1; i <= 10; i++)
        ans = (ans + dp[n][i]) % 1000000000;

    return ans;
}

/**
 * 쉬운 계단 수: 인접한 모든 자리의 차이가 1인 수 ex)45656
 * 쉬운 계단 수는 앞서 자릿수에서 (현재 수 - 1)로 끝나는 수와 (현재 수 + 1)로 끝나는 수에 현재 수를 더해서 만들 수 있다
 * 1의 자릿수부터 n자리까지 0 ~ 9로 끝나는 쉬운 계단 수의 개수를 모두 구해서 저장해가자
 *
 * ex) 2자리이며 끝나는 수가 3인 쉬운 계단 수 (23, 43)
 * = 1자리고 끝나는 수가 2인 경우(2) + 1자리고 끝나는 수가 4인 경우(4)
 *
 * 0번 인덱스를 포함해서 사용하는데 [현재 인덱스 - 1]에 접근해야 하므로 편의상 1번 인덱스부터 시작 (즉, 실제 수는 인덱스-1)
 */

int main() {
    int n;

    //입력
    cin >> n;

    //출력
    cout << easyStairNum(n) << '\n';

    return 0;
}