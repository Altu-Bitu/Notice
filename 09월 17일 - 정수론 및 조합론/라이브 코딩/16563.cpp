#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int SIZE = 5000000;

//소수 경로 저장해서 리턴하는 함수
vector<int> isPrime() {
    vector<int> prime(SIZE + 1, 0);

    //먼저 모든 수를 소수라 가정하고, i번째 인덱스에 i값 저장
    for (int i = 2; i <= SIZE; i++)
        prime[i] = i;

    //소수 판별
    for (int i = 2; i <= sqrt(SIZE); i++) {
        if (prime[i] == i) { //소수라면
            for (int j = i * i; j <= SIZE; j += i) { //배수에 소수(i) 저장
                if (prime[j] == j) { //저장된 소수가 없을 경우만
                    prime[j] = i; //소수 저장
                }
            }
        }
    }

    return prime;
}

int main() {
    //입출력 속도 향상
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;

    //입력
    cin >> n;

    //미리 최대 크기까지의 소수 경로 저장
    vector<int> prime = isPrime();

    //입력+연산+출력
    while (n--) {
        //소인수분해할 수 입력
        cin >> k;
        //소인수분해 결과 출력
        while (k > 1) {
            cout << prime[k] << ' ';
            k = k / prime[k];
        }
        cout << '\n';
    }
    return 0;
}