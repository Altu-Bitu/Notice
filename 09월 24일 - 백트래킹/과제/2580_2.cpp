#include<iostream>

using namespace std;

const int MAX = 9; //스도쿠 한 행 사이즈

int sudoku[MAX][MAX];         //스도쿠 정보
bool check_row[MAX][MAX + 1]; //각 행의 숫자 존재 여부 체크
bool check_col[MAX][MAX + 1]; //각 열의 숫자 존재 여부 체크
bool check_3x3[MAX][MAX + 1]; //각 3x3 사각형의 숫자 존재 여부 체크
bool found = false;           //스도쿠 채웠는지 확인

/**
 * 9X9의 스도쿠에서 각 행, 열, 3x3 사각형에 1~9가 존재하는지 체크하는 2차원 배열 활용
 * 각 2차원 배열의 행: 어느 부분에 대한 체크인지(행, 열, 3x3), 0번 인덱스부터 시작
 * 각 2차원 배열의 열: 1 ~ 9 숫자 체크
 *
 * 행과 열은 바로 사용하면 됨
 * (ex) check_row[3][2] = true;  //3행에 2라는 숫자가 존재한다는 것
 *      check_col[8][9] = false; //8열에 9라는 숫자가 존재하지 않는다는 것
 *
 * 3x3 사각형 (하나를 각 구역이라고 표현)
 * -> 행을 3으로 나눈 몫과 열을 3으로 나눈 몫으로 구역 0부터 8까지 다음과 같이 나타낼 수 있음
 * (0,0) (0,1) (0,2)
 * (1,0) (1,1) (1,2)
 * (2,0) (2,1) (2,2)
 * -> 1차원 배열 인덱스로 구분하기 위해 각 (행 / 3)값에 3을 곱한 후 (열 / 3)을 더함
 * -> 따라서 3x3 사각형의 구간은 (row / 3) * 3 + (col / 3) = 0 ~ 8인 구간으로 나눌 수 있음
 */

void fillSudoku(int idx) {
    if (idx == MAX * MAX) {
        found = true;
        return;
    }
    int row = idx / MAX;
    int col = idx % MAX;

    if (sudoku[row][col])
        return fillSudoku(idx + 1);

    for (int i = 1; i <= MAX; i++) {
        if (!check_row[row][i] && !check_col[col][i] && !check_3x3[(row / 3) * 3 + col / 3][i]) {
            check_row[row][i] = true;
            check_col[col][i] = true;
            check_3x3[(row / 3) * 3 + col / 3][i] = true;
            sudoku[row][col] = i;
            fillSudoku(idx + 1);
            if (found)
                return;
            check_row[row][i] = false;
            check_col[col][i] = false;
            check_3x3[(row / 3) * 3 + col / 3][i] = false;
            sudoku[row][col] = 0;
        }
    }
}

/**
 * 80ms
 */

int main() {
    //입력
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cin >> sudoku[i][j];
            if (sudoku[i][j]) { //스도쿠 상태 보고, check배열들 초기화
                check_row[i][sudoku[i][j]] = true;
                check_col[j][sudoku[i][j]] = true;
                check_3x3[(i / 3) * 3 + j / 3][sudoku[i][j]] = true;
            }
        }
    }

    //연산
    fillSudoku(0);

    //출력
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            cout << sudoku[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}