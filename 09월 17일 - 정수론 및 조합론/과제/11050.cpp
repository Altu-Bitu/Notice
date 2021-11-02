#include <iostream>

using namespace std;

/**
 * 이항계수 문제
 * 이항계수 = C(n,k) 를 이용하여 푸는 조합론 문제
 */

//팩토리얼 함수
int fac(int n) {
    if (n == 0)
        return 1;
    return n * fac(n - 1);
}

int main() {
    int n, k;

    //입력
    cin >> n >> k;

    //이항계수, C(n,k) 공식과 동일
    int ans = fac(n) / (fac(n - k) * fac(k));

    //출력
    cout << ans << '\n';

    return 0;
}