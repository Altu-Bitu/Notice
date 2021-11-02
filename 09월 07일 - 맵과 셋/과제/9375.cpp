#include <iostream>
#include <map>

using namespace std;

/**
 * 같은 종류의 옷이 각각 몇 벌 있는지만 알면 됨
 */
int main() {
    int t, n;
    string outfit, kind;

    cin >> t;
    while (t--) {
        map<string, int> m;

        //입력
        cin >> n;
        while (n--) {
            cin >> outfit >> kind;
            m[kind]++;
        }

        //연산
        int result = 1;
        for (auto iter = m.begin(); iter != m.end(); iter++)
            result *= (iter->second + 1); //해당 종류의 옷을 입기(iter->second) + 안 입기(1)

        //출력
        //알몸인 경우 제외
        cout << result - 1 << '\n';
    }
}