#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int SIZE = 7; //배열 크기
const int RANGE = 10000; //주어지는 수 범위

int n, m, leng; //leng: 서로 다른 수의 개수
int num[SIZE], ans[SIZE];

void backtracking(int cnt) {
    if (cnt == m) { //길이 m이라면 (기저조건)
        for (int i = 0; i < cnt; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < leng; i++) { //중복 수 모두 제거되었으므로 따로 체크할 필요 없이 수열을 만든다
        ans[cnt] = num[i];
        backtracking(cnt + 1);
    }
}

/**
 * [백트래킹 풀이] (176ms)
 * 조건: 같은 수 여러 번 사용 가능, 수열은 중복되면 안됨, 사전 순으로 출력
 * '같은 수 여러 번' -> 완전탐색
 * '수열 중복되면 안됨'
 * -> 현재 중복으로 들어오는 수가 존재하여, 그냥 완전탐색을 진행하면 중복 수열이 생김
 * -> 따라서, 중복으로 들어오는 수를 제거하여 다른 배열에 저장한 후, 완전탐색을 하자!
 * '사전 순으로 출력' (N과 M(1)과 동일)
 */

int main() {
    vector<bool> check(RANGE, false); //중복 수 제거하며 받기 위한 체크 배열
    int a;

    //입력 (중복 제거하며 num 배열에 저장하기)
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (!check[a]) //처음 나온 수라면
            num[leng++] = a;
        check[a] = true;
    }

    //연산
    sort(num, num + leng);

    //연산 + 출력
    backtracking(0);

    return 0;
}