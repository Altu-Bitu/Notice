#include <iostream>
#include <vector>

using namespace std;

bool isGroup(string str) {
    char cur = '.'; //현재의 문자
    vector<bool> alphabet(26, false); //각 알파벳의 등장 여부를 체크

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == cur) //연속해서 나타난 문자
            continue;
        //이전의 문자와 다른 문자가 나타났을 때
        if (alphabet[str[i] - 'a']) //이전에 등장했던 문자면 떨어져서 나타난 것
            return false;
        cur = str[i]; //현재의 문자 갱신
        alphabet[str[i] - 'a'] = true; //등장 체크
    }
    return true;
}

int main() {
    int n, result = 0;

    //입력
    cin >> n;
    while (n--) {
        string word;
        cin >> word;

        //연산
        if (isGroup(word)) //그룹 단어인지 확인
            result++;
    }

    //출력
    cout << result;
}