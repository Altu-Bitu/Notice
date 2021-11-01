#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 26;

//알파벳별 등장횟수 저장
vector<int> alphaMap(string str) {
    vector<int> result(SIZE, 0);
    for (int i = 0; i < str.size(); i++)
        result[str[i] - 'A']++;
    return result;
}

/**
 * 단어가 같은 구성일 조건
 * 1. 두 개의 단어가 같은 종류의 문자로 이루어짐
 * 2. 같은 문자는 같은 개수만큼 있음
 *
 * 비슷한 단어의 조건
 * 1. 한 단어에서 한 문자를 더하거나, 빼면 같은 구성이 됨
 *    -> 두 단어에서 다른 문자의 개수가 총 1개
 * 2. 한 단어에서 한 문자를 바꾸면 같은 구성이 됨
 *    -> 두 단어에서 다른 문자의 개수가 총 2개
 *    -> !주의! 이때, 두 단어의 길이가 같아야 함 cf) doll | do
 */
int main() {
    int n, ans = 0;
    string source, target;

    //입력
    cin >> n >> source;

    //연산
    vector<int> source_alpha = alphaMap(source);
    while (--n) {
        cin >> target;

        int diff = 0;
        vector<int> target_alpha = alphaMap(target);
        for (int i = 0; i < SIZE; i++) //두 단어의 차이
            diff += abs(source_alpha[i] - target_alpha[i]);
        if (diff <= 1 || (diff == 2 && source.size() == target.size())) //문자를 더하거나, 빼거나, 바꾸거나
            ans++;
    }

    //출력
    cout << ans;
}