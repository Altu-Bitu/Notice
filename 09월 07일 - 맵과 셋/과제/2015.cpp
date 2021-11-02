#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

/**
 * S(i,j): i ~ j 까지의 부분합, S[i]: 1(시작인덱스) ~ i 까지의 부분합
 * 부분합 공식: S(i,j) = S[j] - S[i] (단, i < j)
 * 따라서 부분합이 k값이 되는 경우의 수는 S[j] - S[i] = k 가 되는 경우의 수 찾으면 됨 -> 그냥 찾으면 O(n^2) 으로 시간초과
 * i가 고정되었다 가정할 때, S(x,i) = S[i] - S[x] = k 를 만족하는 x의 개수가 S(x,i) 중 k가 되는 경우의 수
 * 따라서 i를 1 ~ n 까지 돌리며 S(x,i) = k 인 경우의 수 계속 더해주면 됨 -> O(n)
 * 이때, S[i] - S[x] = k 를 만족하는 x의 개수는 S[x] = S[i] - k 를 만족하는 x의 개수와 같다.
 * (실수 주의) n, k 모두 int 범위지만 최대 부분합 개수가 200000^2 보다 크므로 정답에서 long long 써야하는 문제
 */

int main() {
    vector<int> num, s; //num: 입력 배열, s: 부분합 배열
    map<int, ll> m; //key: S[x] 즉 S[i] - k의 값, value: x의 개수
    int n, k;
    ll ans = 0;

    //입력
    cin >> n >> k;
    num.assign(n + 1, 0); //인덱스 1부터 시작하기 위해 n+1 크기 할당
    s.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        //부분합 구하기
        s[i] = num[i] + s[i - 1]; //인덱스 1부터 시작해야 이 과정에서 런타임 에러 안남
    }

    //연산
    for (int i = 1; i <= n; i++) {
        if (s[i] == k) //S[i] == k 일 경우
            ans++;
        ans += m[s[i] - k]; //S[x] = S[i] - k 를 만족하는 x의 개수만큼 ans 증가
        m[s[i]]++; //항상 x < i 이여야 하므로 i번째 검사 후 S[i]를 맵에 저장, 이미 존재하면 value 값 증가
    }

    //출력
    cout << ans << '\n';
    return 0;
}