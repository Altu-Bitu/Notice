#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 1e9;

int knapsackCoin(int n, int k, vector<int> &coin) {
    vector<int> dp(k + 1, INF);

    dp[0] = 0; //0가치를 만드는 경우 초기화
    for (int i = 0; i < n; i++) {
        for (int j = coin[i]; j <= k; j++) { //!생각해보기! 배낭 문제에서의 1차원 dp구현과 다른 점은?
            if (dp[j - coin[i]] != INF)
                dp[j] = min(dp[j], dp[j - coin[i]] + 1);
        }
    }

    if (dp[k] == INF)
        return -1;
    return dp[k];
}

/**
 * 배낭 문제(12865)와 유사
 * 현재 가치를 만드는 동전 개수의 최솟값 저장
 * = max(기존 값, [현재 가치 - 현재 사용하려는 동전 가치]의 동전 개수 최솟값 + 1)
 *
 * !주의! 최솟값을 찾는 문제이므로 dp 배열 초기화 중요
 * !주의! 배낭 문제와 다르게, 꼭 현재 가치를 정확하게 만드는 경우만 검사해야함
 */

int main() {
    int n, k;

    //입력
    cin >> n >> k;
    vector<int> coin(n, 0);
    for (int i = 0; i < n; i++)
        cin >> coin[i];

    //연산 + 출력
    cout << knapsackCoin(n, k, coin) << '\n';

    return 0;
}