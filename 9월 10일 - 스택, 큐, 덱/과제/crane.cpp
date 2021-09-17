#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<stack<int>> dolls;

int moveDoll(vector<vector<int>> &board, vector<int> &moves) {
    int cnt = 0; //사라진 인형의 수
    stack<int> bucket; //인형을 옮겨 담을 바구니

    for (int i = 0; i < moves.size(); i++) {
        int pos = moves[i] - 1; //moves의 값이 1부터 시작하기 때문에 0부터 시작하도록 바꿔주기
        if (dolls[pos].empty()) //옮길 인형이 없음
            continue;

        //인형 들기
        int doll = dolls[pos].top();
        dolls[pos].pop();

        if (!bucket.empty() && doll == bucket.top()) { //같은 인형이 연속해서 쌓였다면
            cnt += 2;
            bucket.pop();
        } else //다른 인형이 쌓인다면
            bucket.push(doll);
    }
    return cnt;
}

stack<int> dollStack(vector<vector<int>> &board, int idx) {
    stack<int> s;
    for (int i = board.size() - 1; i >= 0; i--) { //idx열의 맨 바닥에 있는 인형부터 스택에 넣기
        int doll = board[i][idx];
        if (doll == 0) //더이상 인형이 없음
            break;
        s.push(doll);
    }
    return s;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    for (int i = 0; i < board.size(); i++) //각 열의 인형들을 스택에 넣기
        dolls.push_back(dollStack(board, i));
    int answer = moveDoll(board, moves); //인형 옮기기
    return answer;
}

/**
 * 각 열의 인형을 스택에 넣고 관리하기!
 * 1부터 시작하는 인덱스를 주의하고, 인형은 한 번에 2개씩 사라진다는 것을 기억하기
 */
int main() {
    vector<vector<int>> board = {{0, 0, 0, 0, 0},
                                 {0, 0, 1, 0, 3},
                                 {0, 2, 5, 0, 1},
                                 {4, 2, 4, 4, 2},
                                 {3, 5, 1, 3, 1}};
    vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4};
    cout << solution(board, moves);
}