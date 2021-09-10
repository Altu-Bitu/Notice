#include <iostream>
#include <vector>

using namespace std;

/**
 * 주어진 문제의 별의 규칙을 찾아서 푸는 문제
 * 별들의 가로(세로) 길이가 N에 따라 4*N-3 값을 가진다는 것을 파악해야 함
 * 그 다음, 별 모양의 규칙 파악
 * 별을 자세히 들여다보면 테두리만 그려진 별로 가로(세로) 길이가 4씩 줄어드는 것을 알 수 있음
 */

void fillStar(int width, vector<vector<char> > &star, int row, int col) {
    //width가 1이면 더 이상 동작 수행 불가. 다시 돌아가면서 별 채우기 수행
    if (width == 1) {
        star[row][col] = '*';
        return;
    }

    //width는 4씩 줄어들고, 시작(왼쪽 위) x, y 위치값은 2씩 증가
    fillStar(width - 4, star, row + 2, col + 2);

    //테두리 별 채우기
    for (int i = row; i < row + width; i++) {
        //(i,col): 왼쪽 열 테두리, (row,i): 위쪽 행 테두리, (row+width-1,i): 아래쪽 행 테두리, (i,col+width-1): 오른쪽 열 테두리
        star[i][col] = star[row][i] = star[row + width - 1][i] = star[i][col + width - 1] = '*';
    }

}

int main() {
    int n, width;

    //입력
    cin >> n;
    width = 4 * n - 3; //출력되는 별의 n값에 따른 가로 세로 길이
    vector<vector<char> > star(width, vector<char>(width, ' ')); // 공백으로 찬 width*width 벡터 생성

    //연산

    //3번째와 4번째 인덱스는 각각 시작(왼쪽 위) 위치의 row, col 값
    fillStar(width, star, 0, 0);

    //출력
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++)
            cout << star[i][j];
        cout << '\n';
    }
    return 0;
}