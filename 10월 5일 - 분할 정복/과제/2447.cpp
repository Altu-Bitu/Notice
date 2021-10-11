#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> board;

void star(int row, int col, int size) {
    //Conquer : size의 크기가 1
    if (size == 1) {
        board[row][col] = '*';
        return;
    }

    //Divide : 9등분 하는데, 가운데 부분에 대해선 함수 호출하지 않음
    int next_size = size / 3;
    for (int i = 0; i <= next_size * 2; i += next_size) {
        for (int j = 0; j <= next_size * 2; j += next_size) {
            if (i == next_size && j == next_size) //가운데 부분
                continue;
            star(row + i, col + j, next_size);
        }
    }
}

/**
 * ***   (0, 0) (0, 1) (0, 2)
 * * *   (1, 0) (1, 1) (1, 2)
 * ***   (2, 0) (2, 1) (2, 2)
 *
 * 1. 가운데 부분에 대해서만 함수를 호출하지 않으면 됨
 * 2. 왼쪽 맨위 좌표를 (r, c)라 하고, 배열의 크기를 size라고 할 때, 가운데 부분은 (r+(size/3), c+(size/3))
 * 3. size가 1이될 때까지 나누기
 */
int main() {
    int n;

    //입력
    cin >> n;
    board.assign(n, vector<char>(n, ' '));

    //연산
    star(0, 0, n);

    //출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << board[i][j];
        cout << '\n';
    }
}