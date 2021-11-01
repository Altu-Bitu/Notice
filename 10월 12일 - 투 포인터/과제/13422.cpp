#include <iostream>
#include <vector>

using namespace std;

int steal(vector<int> &house, int n, int m, int k) {
    //윈도우 초기화
    int money = 0;
    for (int i = 0; i < m; i++)
        money += house[i];

    if (n == m) //훔칠 수 있는 경우 딱 1개인 경우
        return money < k;

    int ans = 0;
    int left = 0, right = m - 1;
    do { //원형태로 윈도우를 옮겨야 하기 때문에 종료조건은 left가 초기값(=0)이 됐을 때
        if (money < k) //훔칠 수 있음
            ans++;

        money -= house[left];

        //윈도우의 양 끝 이동
        left = (left + 1) % n;
        right = (right + 1) % n;

        money += house[right];
    } while (left);
    return ans;
}

/**
 * 1. 연속해서 훔쳐야 할 집이 m으로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * !주의! 마을에 있는 집의 개수와 도둑이 훔칠 집의 개수가 같을 때(n==m) 도둑이 훔칠 수 있는 경우의 수 1개!
 */
int main() {
    int t, n, m, k;

    cin >> t;
    while (t--) {
        //입력
        cin >> n >> m >> k;
        vector<int> house(n, 0);
        for (int i = 0; i < n; i++)
            cin >> house[i];

        //연산 & 출력
        cout << steal(house, n, m, k) << '\n';
    }
}