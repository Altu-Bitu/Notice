#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int SIZE = 1000000;

//에라토스테네스의 체, 미리 SIZE까지의 소수 판단
vector<bool> isPrime() {
    vector<bool> is_prime(SIZE + 1, true); //소수 판단 여부 저장

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= sqrt(SIZE); i++) {
        if (is_prime[i]) { //i가 소수라면
            for (int j = i * i; j <= SIZE; j += i)
                is_prime[j] = false; //i의 배수 제거
        }
    }

    return is_prime;
}

//골드바흐의 추측 판단 함수
int checkGoldbach(int n, vector<bool> &is_prime) {
    for (int i = 3; i <= n / 2; i += 2) { //홀수만 검사, n/2 이상의 값은 어차피 n-i를 통해 검사되므로 n/2까지 검사
        if (is_prime[i] && is_prime[n - i]) { //두 홀수 모두 소수라면 (골드바흐의 추측이 맞은 경우)
            return i; //두 홀수 소수 중 작은 값 리턴
        }
    }
    return 0; //골드바흐의 추측이 틀린 경우
}

/**
 * "골드바흐의 추측"
 * 4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다. -> 이를 증명하는 문제
 * -> 에라토스테네스의 체를 활용하여 미리 SIZE 까지의 소수 판별
 * -> 두 홀수 소수의 합으로 나타낼 수 있는지 판단
 */

int main() {
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<bool> is_prime = isPrime(); //소수 판단 여부 저장

    while (true) {
        //입력
        cin >> n;
        if (n == 0)
            break;

        //연산
        int prime = checkGoldbach(n, is_prime); //골드바흐의 추측이 맞는지 체크
        if (prime) //맞다면 -> 두 홀수 소수 중 작은 값 리턴받은 경우
            cout << n << " = " << prime << " + " << n - prime << '\n';
        else //틀리다면 -> 0 리턴받은 경우
            cout << "Goldbach's conjecture is wrong.\n";

    }

    return 0;
}