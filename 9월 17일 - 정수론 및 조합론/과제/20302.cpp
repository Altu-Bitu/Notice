#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 100000;

vector<int> prime(SIZE + 1, 0); //소수 경로 저장
vector<int> exponent(SIZE + 1, 0); //연산 과정에서 각 소수의 지수 저장

//소수 경로 저장해서 리턴하는 함수
void isPrime() {
    //먼저 모든 수를 소수라 가정하고, i번째 인덱스에 i값 저장
    for (int i = 2; i <= SIZE; i++) prime[i] = i;

    //소수 판별
    for (int i = 2; i * i <= SIZE; i++) {
        if (prime[i] == i) { //소수라면
            for (int j = i * i; j <= SIZE; j += i) { //배수에 소수(i) 저장
                if (prime[j] == j) { //저장된 소수가 없을 경우만
                    prime[j] = i; //소수 저장
                }
            }
        }
    }
}

//소인수분해해서 지수 계산하는 함수
void countExponent(int a, int cnt) {
    while (a > 1) { //소인수분해, prime[a] = 소인수
        exponent[prime[a]] += cnt; //연산이 곱하기라면 cnt = 1 이여서 지수 증가, 나누기라면 cnt = -1로 지수 감소
        a = a / prime[a];
    }
}

//연산이 끝난 후, 소인수의 지수에 음수 있는지 판단 -> 있다면 유리수 -> true 리턴
bool isRationalNumber() {
    for (int i = 2; i <= SIZE; i++) {
        if (exponent[i] < 0) //유리수라면
            return true;
    }
    return false;
}

/**
 * [민트초코 문제 설명]
 * 수식의 결과가 정수면 민트초코, 유리수면 치약
 *
 * [문제 풀이]
 * 수는 소인수분해하여 나타낼 수 있고, 지수가 음수인 소인수가 하나라도 존재한다면 유리수
 * 문제의 수식은 * , / 만 들어옴
 * 따라서, 문제의 수식대로 계산하는 과정에서 소인수의 지수를 계산하여 저장하자
 * 소인수분해 방법은 '어려운 소인수분해' 문제 참고
 * !주의! 정수 유리수 판단에서는 부호가 상관 없음 -> 모두 양수로 해서 계산하자
 * !주의! 0이 곱해지는 경우 무조건 정수이므로 예외처리
 */

int main() {
    int n, a;
    char c;

    isPrime(); //소수 경로 저장

    //입력
    cin >> n;
    cin >> a; //처음 수 미리 입력

    if (a == 0) { //처음 수 0 -> 결과 값 0 -> 정수이므로 바로 민트초코 출력 후 종료
        cout << "mint chocolate\n";
        return 0;
    }
    countExponent(abs(a), 1); //처음 수는 곱하기로 계산

    //(수식 + 수) 쌍으로 (n-1) 개 입력 + 연산
    for (int i = 1; i < n; i++) {
        cin >> c >> a;

        if (a == 0) { //0을 곱함 -> 결과값 0 -> 정수이므로 바로 민트초코 출력 후 종료
            cout << "mint chocolate\n";
            return 0;
        }

        if (c == '*') //곱하기라면 -> 지수 증가
            countExponent(abs(a), 1); //2번째 매개변수: 지수의 증가값
        else //나누기라면 -> 지수 감소
            countExponent(abs(a), -1); //2번째 매개변수: 지수의 감소값
    }

    if (isRationalNumber()) //유리수인 경우
        cout << "toothpaste\n";
    else //0 제외 정수인 경우
        cout << "mint chocolate\n";

    return 0;
}