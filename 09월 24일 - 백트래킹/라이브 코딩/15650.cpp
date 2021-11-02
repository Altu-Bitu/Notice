//
// Created by BaeSuA on 2021-09-24.
//

#include <iostream>

using namespace std;

const int SIZE = 8;

int n, m;
int num[SIZE]; //수열

//재귀함수로 구현한 백트래킹
void backtracking(int cnt, int start) { //start: 오름차순 구현을 위한 시작 인덱스
    if (cnt == m) { //기저조건
        for (int i = 0; i < cnt; i++)
            cout << num[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = start; i <= n; i++) {
            num[cnt] = i; //수열 저장
            backtracking(cnt + 1, i + 1); //호출
    }
}

int main() {
    //입력
    cin >> n >> m;

    //연산 + 출력
    backtracking(0, 1);

    return 0;
}