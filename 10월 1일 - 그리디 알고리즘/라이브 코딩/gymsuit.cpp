//
// Created by BaeSuA on 2021-10-01.
//

#include <iostream>
#include <vector>

using namespace std;

/*
* 학생의 체육복 개수 표시
* 왼쪽 학생부터 양 옆의 학생에게 체육복을 빌릴 수 있을지 검사
* !주의! 왼쪽 학생, 오른쪽 학생 둘 다 빌릴 수 있는 경우 왼쪽 학생한테 빌려야 다음 학생은 또 왼쪽 학생에게 빌릴 수 있게 됨
* 마지막으로 체육복이 1개 이상인 학생 개수 세주기
*/

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> student(n + 1, 1); //학생마다 체육복 개수

    for (int i = 0; i < lost.size(); i++) //체육복을 잃어버린 학생
        student[lost[i]]--;

    for (int i = 0; i < reserve.size(); i++) //여벌 체육복이 있는 학생
        student[reserve[i]]++;

    for (int i = 1; i <= n; i++) { //1번 학생부터 그리디적으로 양 옆으로 체육복을 빌릴 수 있다면 빌리기
        if (student[i]) //이미 체육복 있다면
            continue;
        if (student[i - 1] == 2) { //왼쪽 학생한테 체육복 빌리기
            student[i - 1]--;
            student[i]++;
        } else if (student[i + 1] == 2) { //오른쪽 학생한테 체육복 빌리기
            student[i + 1]--;
            student[i]++;
        }

    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        if (student[i]) //체육복이 있다면
            answer++;
    }

    return answer;
}

//프로그래머스 메인함수
int main() {
    vector<int> lost = {2, 4};
    vector<int> reserve = {1, 3, 5};
    int n = 5;

    cout << solution(n, lost, reserve);

    return 0;
}