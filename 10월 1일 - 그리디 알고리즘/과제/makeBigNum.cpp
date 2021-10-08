#include <iostream>
#include <string>
#include <deque>

using namespace std;

//k개의 수 지워서 큰 수 만드는 함수
string makeBigNum(string number, int l, int k) {
    deque<int> dq;
    int cnt = 0;
    for (int i = 0; i < l; i++) {
        while (!dq.empty() && dq.front() < number[i] - '0' && cnt < k) { //이번 입력이 dq.front()보다 크면서 아직 K개를 지우지 않았다면
            dq.pop_front(); //dq.front() 지우기
            cnt++; //지워진 숫자 증가
        }
        dq.push_front(number[i] - '0'); //이번 입력 삽입
    }
    while (dq.size() > (l - k)) //충분히 지우지 못했다면 앞에서부터(자릿수가 작은 숫자) 지우기
        dq.pop_front();

    string answer = "";
    while (!dq.empty()) { //큰 자릿수부터 정답에 추가
        answer += (dq.back() + '0');
        dq.pop_back();
    }
    return answer;
}

/**
 * k개의 수를 지워나가면서 바로바로 큰 수를 만들어나가자
 * 0번 인덱스부터 차례로 검사해서 일단 큰 수에 포함했다가, 커지는 값이 나오면 그 전의 수를 모두 지운다
 * 마지막으로 남은 수열이 원하는 정답인 큰 수가 된다
 * ex) 1924 에서 2개를 지워서 큰 수를 만들어야 한다면
 *     1->9로 넘어가는 순간 1이 지워짐 -> 9는 큰 수에 포함
 *     2->4로 넘어가는 순간 2가 지워짐 -> 4는 큰 수에 포함
 *     94가 최종 정답
 *
 * 이러한 그리디적 풀이가 가능한 이유 -> number의 순서가 고정되어 있기 때문!
 * !주의! 커지는 값이 나와도, 이미 k번 수를 지웠다면 더 이상 지우면 안됨
 * !주의! 마지막까지 검사했는데 k번 지우지 못했다면 마지막 값들을 지워서 k번을 채움
 */

string solution(string number, int k) {
    return makeBigNum(number, number.length(), k);
}

int main() {
    string number = "1924";
    int k = 2;

    //연산 &출력
    cout << solution(number, k);

    return 0;
}