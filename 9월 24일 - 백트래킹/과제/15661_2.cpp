#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1e5;

vector<vector<int>> power;

//각 팀의 능력치를 계산하는 함수
int calcPower(vector<int> &arr) {
    int result = 0, size = arr.size();

    //모든 Sij의 합
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++)
            result += power[arr[i]][arr[j]] + power[arr[j]][arr[i]];
    }
    return result;
}

//비트의 상태에 따라 팀을 나누는 함수
int splitTeam(int n, int bit) {
    vector<int> start, link;

    /**
     * 비트와 (1<<i)를 and 연산
     * bit = 0011일 때
     * bit & (1<<0) = 0011 & 0001 = 0001(이진수) = 1(십진수)
     * bit & (1<<1) = 0011 & 0010 = 0010(이진수) = 2(십진수)
     * bit & (1<<2) = 0011 & 0100 = 0000(이진수) = 0(십진수)
     * bit & (1<<3) = 0011 & 1000 = 0000(이진수) = 0(십진수)
     */
    for (int i = 0; i < n; i++) {
        if ((bit & (1 << i))) //i번째 비트가 1이면(=연산 결과를 십진수로 바꾼 결과가 1이상이면) i번째 사람은 스타트 팀
            start.push_back(i);
        else //i번째 비트가 0이면(=연산 결과를 십진수로 바꾼 결과가 0이면) i번째 사람은 링크 팀
            link.push_back(i);
    }
    return abs(calcPower(link) - calcPower(start)); //두 팀의 능력치 차이 리턴
}

/**
 * 비트마스킹 풀이 (560ms)
 * 각각의 사람들은 스타트 팀(1)이거나, 링크 팀(0) -> 0, 1 두 가지 비트로 나타낼 수 있음
 *
 * n = 4일 때 (문제에선 1번 사람부터 시작하지만 편의상 0번 사람부터 시작한다고 가정)
 * 0000 : 모두 링크 팀
 * 1111 : 모두 스타트 팀
 * 0001 : 0번 사람은 스타트 팀, (1, 2, 3)번 사람은 링크 팀
 * 1010 : (1, 3)번 사람은 스타트 팀, (0, 2)번 사람은 링크 팀
 *
 * 팀을 나누는 경우의 수는 0000(=0) ~ 1111(=(1<<4)) 총 16개
 * !주의! 각 팀의 인원은 최소 1명 이상이어야 하기 때문에 0000과 1111인 경우를 제외함
 */
int main() {
    int n, min_diff = INF;

    //입력
    cin >> n;
    power.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> power[i][j];
    }

    //연산
    /**
     * 팀을 나누는 모든 경우의 수는 ((2^n)-2)개
     * 하지만, 0011과 1100은 사실상 같은 경우기 때문에 절반만 탐색
     */
    for (int i = 1; i < ((1 << n) / 2); i++)
        min_diff = min(min_diff, splitTeam(n, i));

    //출력
    cout << min_diff;
}
