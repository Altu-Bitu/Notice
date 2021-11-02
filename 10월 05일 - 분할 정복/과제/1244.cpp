#include <iostream>
#include <vector>

using namespace std;

//남학생의 스위치 바꾸기
vector<int> changeSwitchBoy(int n, int number, vector<int> switches) {
    for (int i = number; i <= n; i += number) //배수에 있는 스위치 바꾸기
        switches[i] = !switches[i];

    return switches;
}

//여학생의 스위치 바꾸기
vector<int> changeSwitchGirl(int n, int number, vector<int> switches) {
    switches[number] = !switches[number];
    for (int i = 1; i < number; i++) {
        if ((number + i > n) || (switches[number - i] != switches[number + i])) //스위치 범위 넘어가거나 좌우 대칭이 아니면
            break;
        switches[number - i] = !switches[number - i];
        switches[number + i] = !switches[number + i];
    }

    return switches;
}

/**
 * 남학생 -> 해당 번호의 배수에 해당하는 스위치 상태 바꾸기
 * 여학생 -> 해당 번호를 중심으로 좌우 대칭이면서 가장 많은 스위치 포함하는 구간의 상태 모두 바꾸기
 *
 * 좌우 대칭 검사 시, 스위치 범위 주의 (주어진 스위치 범위 넘어가지 않도록)
 * 스위치 20개씩 출력하는 부분 주의
 */
int main() {
    int n, m;
    int student, number;

    //입력
    cin >> n;
    vector<int> switches(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> switches[i];

    //입력 & 연산
    cin >> m;
    while (m--) {
        cin >> student >> number;
        if (student == 1)
            switches = changeSwitchBoy(n, number, switches);
        else
            switches = changeSwitchGirl(n, number, switches);
    }

    //출력
    for (int i = 1; i <= n; i++) {
        cout << switches[i] << ' ';
        if (i % 20 == 0)
            cout << '\n';
    }
    return 0;
}