#include <iostream>

using namespace std;

int ans = 0;
bool found = false; //생각해보기 : 이 변수가 없다면 어떻게 되나요?

void divide(int r, int c, int row, int col, int size) {
    //Conquer : 찾던 위치에 도달함
    if (row == r && col == c) { //찾던 위치
        found = true;
        return;
    }
    if (found)
        return;

    //Combine : (r, c)보다 먼저 탐색하는 원소의 개수 세기
    if (r < row || r >= row + size || c < col || c >= col + size) { //이 사분면 안에 (r, c)가 없을 때
        ans += size * size; //(r, c) 앞에 (size * size)개의 원소가 있음
        //cout << row << ' ' << col << ' ' << size << '\n'; //이해가 어렵다면 출력해보기
        return;
    }

    //Divide : 4개의 사분면으로 나누기
    int next_size = size / 2;
    for (int i = 0; i <= next_size; i += next_size) {
        for (int j = 0; j <= next_size; j += next_size)
            divide(r, c, row + i, col + j, next_size);
    }
}

/**
 * 1. 종이 4등분 하기
 * 2. z의 형태에 맞춰 1->2->3->4 사분면 순서로 탐색
 * 3. 만약 sub-사분면이 (r, c)의 범위를 넘어서면, 이 사분면은 (r, c)보다 먼저 탐색하는 사분면 (왜그런지 생각해보기)
 *    sub-사분면의 크기는 (sub-size * sub-size)이므로 (r, c) 앞에 그만큼의 원소가 있음
 */
int main() {
    int n, r, c;

    //입력
    cin >> n >> r >> c;

    //연산
    divide(r, c, 0, 0, 1 << n);

    //출력
    cout << ans;
}