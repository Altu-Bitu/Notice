//
// Created by iw040 on 2021-10-12.
//

#include <iostream>
#include <vector>

using namespace std;

//슬라이딩 윈도우로 최대 방문자 수를 구하고, 그 기간의 수를 리턴
pair<int, int> maxVisitor(int n, int x, vector<int> &visitor) {
    //윈도우 초기화
    int section_visitor = 0;
    for (int i = 0; i < x; i++) //첫날부터 x일 동안의 방문자 수
        section_visitor += visitor[i];

    int ans = section_visitor; //최대 방문자 수
    int cnt = 1; //최대 방문자 수인 기간의 수

    //슬라이딩
    for (int i = x; i < n; i++) {
        section_visitor -= visitor[i - x]; //이번 윈도우에 제외되는 값
        section_visitor += visitor[i]; //이번 윈도우에 추가되는 값
        if (section_visitor > ans) { //최대 방문자 수가 갱신된다면
            cnt = 1;
            ans = section_visitor;
        } else if (section_visitor == ans) //최대 방문자 수와 같다면
            cnt++;
    }
    return make_pair(ans, cnt);
}

int main() {
    int n, x;

    //입력
    cin >> n >> x;
    vector<int> visitor(n, 0);
    for (int i = 0; i < n; i++)
        cin >> visitor[i];

    //연산
    pair<int, int> ans = maxVisitor(n, x, visitor);

    //출력
    if (ans.first == 0) { //최대 방문자 수가 0명이라면
        cout << "SAD\n";
        return 0;
    }
    cout << ans.first << '\n' << ans.second;
}