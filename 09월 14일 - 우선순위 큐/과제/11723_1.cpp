#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int SIZE = 21;

/**
 * 배열 사용 풀이
 * 1. 집합에는 1~20의 숫자만 입력 or 제거됨 (=true or false)
 * 2. 크기 21의 bool 배열을 선언
 * 3. 입력은 true 처리, 제거는 false 처리
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, num;
    string cmd;
    vector<bool> s(SIZE, false);

    cin >> m;
    while (m--) {
        cin >> cmd;
        if (cmd == "all") { //1~20까지 true가 되도록 재할당
            s.assign(SIZE, true);
            continue;
        }
        if (cmd == "empty") { //1~20까지 false가 되도록 재할당
            s.assign(SIZE, false);
            continue;
        }

        cin >> num;
        if (cmd == "add") { //num을 true 처리
            s[num] = true;
            continue;
        }
        if (cmd == "remove") { //num을 false 처리
            s[num] = false;
            continue;
        }
        if (cmd == "check") { //num의 상태 확인
            cout << s[num] << '\n';
            continue;
        }
        if (cmd == "toggle") { //true->false, false->true
            s[num] = !s[num];
            continue;
        }
    }
}