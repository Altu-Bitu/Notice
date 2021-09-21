#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int SIZE = 21;

/**
 * 비트마스크 풀이
 * 1. true or false 라는 2가지 상태는 0 or 1로 나타낼 수 있음 (=이진수)
 * 2. int형에 담을 수 있는 가장 큰 수는 2^31-1 이고, 입력으로 들어오는 수는 최대 20이므로 비트마스크 사용 가능
 *
 * ex)
 * 0000 0000 0000 0000 0010 => {1}
 * 0001 1111 1111 1111 1110 => {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}
 * 0000 0000 0010 0000 1010 => {1, 3, 9}
 *
 * 비트마스크에 대해 따로 알아보는걸 추천합니다.
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, num;
    string cmd;
    int s = 0;

    cin >> m;
    while (m--) {
        cin >> cmd;
        if (cmd == "all") {
            s = (1 << SIZE) - 1;
            continue;
        }
        if (cmd == "empty") {
            s = 0;
            continue;
        }

        cin >> num;
        if (cmd == "add") { //OR 연산
            s |= (1 << num);
            continue;
        }
        if (cmd == "remove") { //NOT 연산 후 AND 연산
            s &= ~(1 << num);
            continue;
        }
        if (cmd == "check") { //AND 연산
            int tmp = s & (1 << num);
            cout << ((tmp == 0) ? 0 : 1) << '\n';
            continue;
        }
        if (cmd == "toggle") { //XOR 연산
            s ^= (1 << num);
            continue;
        }
    }
}