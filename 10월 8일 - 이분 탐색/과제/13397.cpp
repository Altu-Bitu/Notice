#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

//구간의 점수의 최댓값이 score일 때 나뉘는 구간의 개수
int cntSection(int score) {
    //첫번째 구간의 시작
    int cnt = 1;
    int min_value = arr[0], max_value = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        min_value = min(min_value, arr[i]);
        max_value = max(max_value, arr[i]);
        if (max_value - min_value > score) { //구간의 점수가 score를 초과한다면 새로운 구간 만들기
            cnt++;
            min_value = arr[i];
            max_value = arr[i];
        }
    }
    return cnt;
}

int lowerSearch(int left, int right, int target) {
    int ans = 0;
    while (left <= right) {
        //구간의 점수의 최댓값이 mid일 때, 몇 개의 구간이 만들어지는가?
        int mid = (left + right) / 2;
        int section = cntSection(mid);

        if (section <= target) {
            ans = mid;
            right = mid - 1;
        } else if (section > target)
            left = mid + 1;
    }
    return ans;
}

/**
 * 배열을 M개 이하의 구간으로 나눈다. 나눈 구간의 점수의 최댓값을 최소로 만든 결과는?
 * -> 구간의 점수의 최댓값이 k라고 할 때, 몇 개의 구간이 필요한가?
 *
 * left (구간 점수의 최댓값의 최솟값) : 배열의 모든 원소가 같다면 구간의 점수는 항상 0이다. 그러므로 구간의 점수의 최댓값도 0이 된다.
 * right (구간 점수의 최댓값의 최댓값) : 구간이 1개라면 그 점수는 가장 큰 값과 가장 작은 값의 차이와 같다.
 */
int main() {
    int n, m;
    int min_value = 10001, max_value = 0;

    //입력
    cin >> n >> m;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        min_value = min(min_value, arr[i]);
        max_value = max(max_value, arr[i]);
    }

    //연산 & 출력
    cout << lowerSearch(0, max_value - min_value, m);
}