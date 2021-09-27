#include <iostream>
#include <vector>

using namespace std;
const int MAX_CHANNEL = 1000000;

vector<bool> broken(11); //버튼별 고장여부

//리모컨의 버튼들로 이 채널을 누를 수 있는지 검사. 만약 누를 수 있다면 눌러야 하는 횟수 리턴
int canPress(int channel) {
    int cnt = 0; //버튼을 눌러야 하는 횟수
    if (channel == 0) //0번 채널일 때
        return !broken[0];
    while (channel != 0) { //누를 채널의 모든 자릿수에 대해
        if (broken[channel % 10]) //하나라도 부서졌다면 누를 수 없음
            return 0;
        channel /= 10;
        cnt++;
    }
    return cnt;
}

/**
 * 0번 채널부터 MAX_CHANNEL까지 모든 채널에 대해 이동 가능 여부를 체크
 * 1,000,000까지만 계산하면 되기 때문에 무식하게 풀어도 시간안에 풀 수 있음
 */
int main() {
    int n, m, button;

    //입력
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> button;
        broken[button] = true;
    }

    //연산
    int min_click = abs(n - 100); //+ 또는 - 버튼 계속 누르기
    if (m == 10) { //버튼이 전부 부서졌다면 숫자를 눌러 이동할 수 없음
        cout << min_click;
        return 0;
    }
    for (int i = 0; i < MAX_CHANNEL; i++) { //i번 채널에 대해
        int press_cnt = canPress(i); //i번 채널에 가기 위해 버튼을 눌러야 하는 횟수
        if (press_cnt != 0) //0이 아니라면 i번 채널로 이동할 수 있음
            min_click = min(min_click, abs(n - i) + press_cnt); //i번 채널 이동 후, i번에서 n번까지 + / - 버튼 누른 값과 최솟값 비교
    }

    //출력
    cout << min_click;
}
