#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 7; //배열 크기

int n, m;
int num[SIZE], ans[SIZE];

void backtracking(int cnt) {
    if (cnt == m) { //길이 m이라면 (기저조건)
        for (int i = 0; i < m; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    int value = -1; //이전에 선택한 값
    for (int i = 0; i < n; i++) {
        if (value != num[i]) { //이전에 탐색한 값이 아니라면(=해당 수 사용 가능하다면)
            value = num[i];
            ans[cnt] = num[i];
            backtracking(cnt + 1);
        }
    }
}

/**
 * [백트래킹 풀이] (184ms)
 * 해설 : https://myunji.tistory.com/309
 */
int main() {
    //입력
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> num[i];

    //연산
    sort(num, num + n);

    //연산 + 출력
    backtracking(0);
}
