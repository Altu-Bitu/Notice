#include <iostream>
#include <vector>

using namespace std;

/**
 * 1. 총감독관은 반드시 1명
 * 2. 부감독관이 필요 없는 시험장이 있음
 * 3. 응시자의 수가 C로 나누어 떨어지지 않는 경우 고려
 * 4. 시험장의 개수, 응시자의 수가 최대이고, B와 C가 최소로 주어지면 결과가 int 범위를 넘을 수 있음
 */
int main() {
    int n, b, c;
    long long result = 0;

    //입력
    cin >> n;
    vector<int> student(n);
    for (int i = 0; i < n; i++)
        cin >> student[i];
    cin >> b >> c;

    //연산
    for (int i = 0; i < n; i++) {
        int cnt = student[i]; //i번 시험장의 응시자 수

        //총감독관 배치
        result++;
        cnt -= b;
        if (cnt <= 0) //부감독관 필요 없음
            continue;

        //부감독관 배치
        result += (cnt / c);
        if (cnt % c != 0) //응시자의 수가 C로 나누어 떨어지지 않는다면 부감독관 한명 추가
            result++;
    }

    //출력
    cout << result;
}