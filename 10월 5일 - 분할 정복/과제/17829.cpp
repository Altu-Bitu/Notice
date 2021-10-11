#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> matrix;

int divide(int row, int col, int size) {
    //Conquer : n의 크기가 1
    if (size == 1)
        return matrix[row][col];

    //Divide : 행렬 4등분 하기
    int next_size = size / 2;
    vector<int> sub_problem;
    for (int i = 0; i <= next_size; i += next_size) {
        for (int j = 0; j <= next_size; j += next_size)
            sub_problem.push_back(divide(row + i, col + j, next_size));
    }

    //Combine : 두번째로 큰 수만 남기기
    sort(sub_problem.begin(), sub_problem.end(), greater<>());
    return sub_problem[1];
}

/**
 * 1. 행렬 4등분 하기
 * 2. 행렬의 크기가 1이라면 원소 리턴
 * 3. 리턴된 원소 4개 모아서 두번째로 큰 수만 리턴
 */
int main() {
    int n;

    //입력
    cin >> n;
    matrix.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    //연산 & 출력
    cout << divide(0, 0, n);
} 