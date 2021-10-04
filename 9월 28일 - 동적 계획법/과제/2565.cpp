#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 강의자료 점화식
 *
 * 시간 복잡도 O(n^2)
 */
int lis(int n, vector<pair<int, int>> &arr) {
    vector<int> dp(n, 1);
    int ans = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i].second > arr[j].second) //증가하는 관계라면
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]); //최장 길이 갱신
    }
    return n - ans;
}

/**
 * dp[i] : 증가하는 부분 수열의 길이가 i인 수 중에 가장 작은 수
 * idx : 가장 긴 증가하는 부분 수열의 길이
 *
 * 시간 복잡도 O(nk) (k는 idx의 크기)
 * 해설 : https://myunji.tistory.com/214
 */
int lisAdv(int n, vector<pair<int, int>> &arr) {
    vector<int> dp(n + 1, 0); //dp[1]을 갱신하기 위해 dp[0] = 0으로 설정
    int idx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = idx; j >= 0; j--) {
            if (arr[i].second > dp[j]) { //증가하는 관계라면
                dp[j + 1] = arr[i].second;
                if (j == idx) //최장 길이 갱신
                    idx++;
                break;
            }
        }
    }
    return n - idx;
}

/**
 * lisAdv에서 line 36~43의 과정을 이분탐색으로 구현
 *
 * 시간 복잡도 O(nlogk) (k는 dp의 크기)
 * 해설 : https://myunji.tistory.com/270
 */
int lisFinal(int n, vector<pair<int, int>> &arr) {
    vector<int> dp;

    for (int i = 0; i < n; i++) {
        int pos = lower_bound(dp.begin(), dp.end(), arr[i].second) - dp.begin();
        if (pos == dp.size()) //최장 길이 갱신
            dp.push_back(arr[i].second);
        dp[pos] = arr[i].second;
    }
    return n - dp.size();
}

/**
 * 전깃줄이 교차하지 않으려면?
 *
 * A[i]<A[j]일 때 B[i]<B[j]
 * -> A를 기준으로 정렬하면 평범한 LIS 문제
 */
int main() {
    int n;

    //입력
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;

    //연산 & 출력
    sort(arr.begin(), arr.end()); //A 전봇대 기준 정렬
    cout << lisFinal(n, arr);
}