#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> withdraw_time;

//시간복잡도 : O(n^2)
int calcTime(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) { //i번째 사람의 대기시간은 0, 1,...,i - 1, i번째 사람의 인출 시간은 합한 값
        for (int j = 0; j <= i; j++)
            sum += withdraw_time[j];
    }
    return sum;
}

//시간복잡도 : O(n)
//어떻게 가능한지 생각해보세요
int calcTimeAdv(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += (withdraw_time[i] * (n - i));
    return sum;
}

/**
 * 인출하는데 필요한 시간이 적은 사람이 먼저 줄을 서도록
 */
int main() {
    int n;

    //입력
    cin >> n;
    withdraw_time.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> withdraw_time[i];

    //연산
    sort(withdraw_time.begin(), withdraw_time.end());

    //출력
    cout << calcTimeAdv(n);
}