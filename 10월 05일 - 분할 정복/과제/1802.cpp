#include <iostream>
#include <algorithm>

using namespace std;

bool divide(string str) {
    //Conquer : 문자열의 길이가 1
    if (str.size() == 1)
        return true;

    //Combine : 가운데 값을 기준으로 접었을 때, 만나게 되는 각 자릿수가 같다면 접을 수 없음
    int len = str.size();
    for (int i = 0; i < len / 2; i++) {
        if (str[i] == str[len - i - 1])
            return false;
    }

    //Divide : 문자열을 절반으로 나누기
    return divide(str.substr(0, len / 2));
}

/**
 * 1. 가운데를 중심으로 접었을 때, 만나게 되는 각 자릿수가 다르다면 접을 수 있음
 * 2. 문자열의 길이가 1이 될 때까지 종이 접기
 *
 * (ex1)
 * 100 0 110
 * 0을 기준으로 접으면 100과 011이 겹쳐짐 -> 접을 수 있음
 *
 * 100에 대해 다시 가운데를 기준으로 나누면 1 0 0
 * 0을 기준으로 접으면 1과 0이 겹쳐짐 -> 접을 수 있음
 *
 * (ex2)
 * 0 0 0
 * 0을 기준으로 접으면 0과 0이 겹쳐짐 -> 접을 수 없음
 */
int main() {
    int t;
    string str;

    cin >> t;
    while (t--) {
        //입력
        cin >> str;

        //연산
        bool ans = divide(str);

        //출력
        cout << ((ans) ? "YES" : "NO") << '\n';
    }
}