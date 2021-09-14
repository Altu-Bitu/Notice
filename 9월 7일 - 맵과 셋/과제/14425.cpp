#include <iostream>
#include <set>

using namespace std;

/**
 * set::find 사용 문제
 * set::find 함수는 찾는 key 값이 존재한다면 해당 iterator를 반환
 * 따라서 찾는 key 값이 없다면 set::end를 반환
 */

int main() {
    set<string> s;
    string str;
    int n, m, ans = 0;

    //입력
    cin >> n >> m;

    //집합 s에 포함되어 있는 문자열 입력
    while (n--) {
        cin >> str;
        s.insert(str);
    }

    //검사해야 하는 문자열 입력
    while (m--) {
        cin >> str;
        //집합 s에 포함되어 있다면 ans 증가
        if (s.find(str) != s.end()) ans++;
    }
    cout << ans << '\n';
    return 0;
}