#include <iostream>
#include <vector>
#include <cmath> //sqrt 사용

using namespace std;

//에라토스테네스의 체에서 k번째 지우는 수 구하는 함수
int isPrime(int n, int k) {
    vector<bool> is_prime(n + 1, true);
    int cnt = 0; //카운트 변수
    //제곱근까지 검사할 경우 반례: k번째 지워지는 수가 제곱근 이상의 소수일 경우
    //따라서 이 문제에서는 꼭 n까지 돌려야 함
    for (int i = 2; i <= n; i++) { 
        if (is_prime[i]) { //i가 소수라면
            //cout << i << '\n'; //디버깅용
            for (int j = i; j <= n; j += i) { //이 문제에서 i번째도 지우는 수에 포함하므로 i부터
                if (!is_prime[j]) //이미 지워진 수라면 넘어감
                    continue;
                //cout << cnt + 1 << "번째 지워지는 수: " << j << '\n'; //디버깅용
                is_prime[j] = false; //i의 배수를 제거
                if (++cnt == k)
                    return j; //k번째 지우는 수 리턴
            }
        }
    }
    //k번째 지우는 수 없다면 -1 리턴
    return -1;
}

int main() {
    int n, k;

    //입력
    cin >> n >> k;

    //연산+출력
    cout << isPrime(n, k) << '\n';

    return 0;
}