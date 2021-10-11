#include <iostream>

using namespace std;

string maxNum(string s) {
    string ans = "";
    string temp = "";
    for (int i = 0; i < s.length(); i++) {
        temp += '0';
        if (s[i] == 'K') { //K가 마지막으로 끝나는 십진수 변환
            temp[0] = '5';
            ans += temp;
            temp = "";
        }
    }
    if (temp.length() >= 1) { //K로 끝나지 않았다면 마지막 M모두 1로 변환
        for (int i = 0; i < temp.length(); i++)
            temp[i] = '1';
        ans += temp;
    }
    return ans;
}

string minNum(string s) {
    string ans = "";
    string temp = "";
    char first = '1';
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'M') {
            temp += first;
            first = '0';
        } else { //'K' -> 그 전까지 M묶음 변환 더하고, K는 따로 변환
            ans += temp + '5';
            temp = "";
            first = '1';
        }
    }
    if (temp.length() >= 1)
        ans += temp;
    return ans;
}

/**
 * [가장 큰 값]
 * 민겸수에서 마지막이 K일 때, K까지 포함하여 십진수로 변환한다
 * K로 끝나지 않는다면 각 M을 모두 하나로 처리한다 (ex. MMM -> 111)
 *
 * [가장 작은 값]
 * K는 무조건 단독으로 변환한다
 * 나머지 M묶음들은 같이 변환한다
 * ex. MMKMM -> 10510
 */

int main() {
    string s;

    //입력
    cin >> s;

    //출력
    cout << maxNum(s) << '\n' << minNum(s) << '\n';

    return 0;
}