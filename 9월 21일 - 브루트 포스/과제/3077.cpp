#include <iostream>
#include <vector>
#include <map>

using namespace std;

/**
 * 맵, 셋에서 다루었던 '추월' 문제와 어떤 점에서 다른지 생각해보세요
 */
int main() {
    int n, ans = 0;
    string input;
    map<string, int> seq; //각 입력과 입력의 인덱스

    //입력
    cin >> n;
    vector<string> answer(n); //현우가 적은 정답
    for (int i = 0; i < n; i++) {
        cin >> input;
        seq[input] = i;
    }
    for (int i = 0; i < n; i++)
        cin >> answer[i];

    //연산
    //모든 n(n-1)/2개의 쌍에서 올바른 순서로 적힌 답안 찾기
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (seq[answer[i]] < seq[answer[j]]) //두 답안의 상대적인 관계가 맞음
                ans++;
        }
    }

    //출력
    cout << ans << '/' << n * (n - 1) / 2;
}