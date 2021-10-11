#include <iostream>
#include <vector>

using namespace std;

vector<int> w;
int ans;

void backtracking(int sum) {
    if (w.size() == 2) { //에너지 구슬이 2개 -> 더 이상 고를 수 없음
        ans = max(ans, sum);
        return;
    }
    for (int i = 1; i < w.size() - 1; i++) { //처음과 마지막 선택 불가이므로
        int temp_w = w[i];
        int sum_w = w[i - 1] * w[i + 1];
        w.erase(w.begin() + i);
        backtracking(sum + sum_w);
        w.insert(w.begin() + i, temp_w);
    }
}

/**
 * 가능한 모든 경우를 구해서 계산하자
 * 이때, 사용한 에너지는 따로 저장해 둔 후에 배열에서 지우고, 다시 돌아왔을 때 저장한 값을 배열에 넣는다.
 */
int main() {
    int n;

    //입력
    cin >> n;
    w.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> w[i];

    //연산
    backtracking(0);

    //출력
    cout << ans << '\n';

    return 0;
}