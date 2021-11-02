#include <iostream>
#include <vector>

using namespace std;
const int MAX = 9;

int sudoku[MAX][MAX];
bool found = false; //스도쿠를 다 채웠는지 확인

/**
 * 같은 행, 열, 구역에 이미 같은 숫자가 있다면 false 리턴
 *
 * 숫자를 입력하려 하는 칸이 (row, col)일 때
 * 같은 행 : (row, 0~8)
 * 같은 열 : (0~8, col)
 *
 * 같은 구역
 * 스도쿠의 크기는 9x9, 같은 구역의 크기는 3x3
 * row = 1, col = 1일 때, 같은 구역은 (0, 0), (0, 1), (0, 2), (1, 0), (1, 1), (1, 2), (2, 0), (2, 1), (2, 2)
 * 공통점 : 행과 열을 3으로 나눈 몫이 같음 (0, 0)
 */
bool promising(int row, int col, int num) {
    for (int i = 0; i < MAX; i++) { //같은 행과 열에 이미 같은 숫자가 있는지 확인
        if (sudoku[i][col] == num || sudoku[row][i] == num)
            return false;
    }

    //같은 구역(3x3)에 이미 같은 숫자가 있는지 확인
    int row_area = row / 3, col_area = col / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[row_area * 3 + i][col_area * 3 + j] == num)
                return false;
        }
    }
    return true;
}

/**
 * 스도쿠의 칸 81개를 하나씩 확인하며 빈공간이라면 숫자를 채움
 *
 *    (행, 열)      인덱싱
 * (0, 0) (0, 1)    0 1
 * (1, 0) (1, 1)    2 3
 *
 * 행을 i, 열을 j라고 하면, 해당 칸의 인덱스는 (i*(판의 크기)+j)로 나타낼 수 있음
 * -> 인덱스 k가 있을 때, 이를 행과 열로 바꾸면 (k/(판의 크기), k%(판의 크기))
 *
 * 스도쿠 판의 마지막 칸은 (8, 8) -> 80
 * 그러므로 종료조건은 k==81
 */
void fillSudoku(int idx) {
    if (idx == MAX * MAX) { //종료조건 : 마지막 칸까지 숫자를 채움
        found = true;
        return;
    }
    int row = idx / MAX; //이번 칸의 행
    int col = idx % MAX; //이번 칸의 열

    if (sudoku[row][col]) //이미 숫자가 채워진 칸이라면 다음 칸으로 넘어감
        return fillSudoku(idx + 1);
    for (int i = 1; i <= MAX; i++) { //1~9까지 넣어보기
        if (promising(row, col, i)) { //이 칸에 숫자 i를 넣을 수 있음
            sudoku[row][col] = i;
            fillSudoku(idx + 1);
            if (found) //생각해보기 : 이 부분이 없으면 어떻게 될까요?
                return;
            sudoku[row][col] = 0;
        }
    }
}

/**
 * 200ms
 */
int main() {
    //입력
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            cin >> sudoku[i][j];
    }

    //연산
    fillSudoku(0);

    //출력
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            cout << sudoku[i][j] << ' ';
        cout << '\n';
    }
}