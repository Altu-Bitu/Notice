#include <iostream>
#include <vector>

using namespace std;

//역추적
vector<int> back(int x, vector<int> &path) { //x = n부터 역추적 시작
    vector<int> result(0);
    while (x != 0) {
        result.push_back(x);
        x = path[x];
    }
    return result;
}

//1로 만드는 최소 연산 횟수 리턴
int makeOne(int n, vector<int> &path) {
    vector<int> dp(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        int min_value = dp[i - 1]; //우선 i - 1 연산 적용한 것으로 저장
        path[i] = i - 1;
        if (!(i % 3) && min_value > dp[i / 3]) {
            min_value = dp[i / 3];
            path[i] = i / 3;
        }
        if (!(i % 2) && min_value > dp[i / 2]) {
            min_value = dp[i / 2];
            path[i] = i / 2;
        }
        dp[i] = min_value + 1;
    }
    return dp[n];
}

/**
 * 기본 문제: 1로 만들기
 *
 * [점화식]
 * dp[i] = (i에 가능한 연산을 적용한 수 중 최소 연산 횟수) + 1
 * dp[i] = min(dp[i / 3], dp[i / 2], dp[i - 1]) + 1
 *
 * [역추적]
 * path: 인덱스가 정수를 나타냄, 해당 수에서 연산을 적용한 다음 수를 저장
 * n부터 역추적 시작
 */

int main() {
    int n;

    //입력
    cin >> n;
    vector<int> path(n + 1, 0); //경로 저장

    //연산
    int ans = makeOne(n, path);
    vector<int> result = back(n, path);

    //출력
    cout << ans << '\n';
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << ' ';
    return 0;
}