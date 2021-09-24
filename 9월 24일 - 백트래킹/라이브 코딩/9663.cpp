//
// Created by BaeSuA on 2021-09-24.
//

#include <iostream>

using namespace std;

const int SIZE = 15;

int n, ans;
bool check_col[SIZE]; //열 체크
bool check_left[SIZE * 2]; //좌하향 대각선 체크
bool check_right[SIZE * 2]; //우하향 대각선 체크

void backtracking(int cnt) { //cnt: 행
    if (cnt == n) { //기저조건, n개의 퀸이 모두 놓임
        ans++; //정답 증가
        return;
    }
    for (int i = 0; i < n; i++) { //i: 열
        if (!check_col[i] && !check_left[cnt + i] && !check_right[cnt - i + n]) { //모두 false여야 배치 가능
            //(cnt, i)에 퀸 배치 -> 그에 따른 열, 좌하향 대각선, 우하향 대각선 체크해줌
            check_col[i] = true;
            check_left[cnt + i] = true;
            check_right[cnt - i + n] = true;
            backtracking(cnt + 1); //다음 행 호출
            //재탐색이 가능하도록 원래상태로 돌려놓음
            check_col[i] = false;
            check_left[cnt + i] = false;
            check_right[cnt - i + n] = false;
        }
    }

}

/**
 * 시간 1684ms
 */

int main() {
    //입력
    cin >> n;

    //연산
    backtracking(0);

    //출력
    cout << ans << '\n';

    return 0;
}