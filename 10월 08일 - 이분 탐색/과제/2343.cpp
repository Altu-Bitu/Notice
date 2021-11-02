#include <iostream>
#include <vector>

using namespace std;

int bluRayNum(vector<int> &lesson, int size) {
    int len = 0; //한 블루레이에 들어가는 강의 길이
    int cnt = 0; //블루레이 개수
    for (int i = 0; i < lesson.size(); i++) {
        if (len + lesson[i] > size) { //한 블루레이에 들어갈 수 있는 길이를 초과
            len = 0;
            cnt++;
        }
        len += lesson[i];
    }

    return cnt + 1; //마지막 구간의 블루레이 더해서 리턴
}

int lowerSearch(vector<int> &lesson, int left, int right, int target) {
    int ans = 0; //m개의 블루레이를 만족할 때 최소 크기
    while (left <= right) {
        int mid = (left + right) / 2;
        int cnt = bluRayNum(lesson, mid); //블루레이 크기가 mid일 때, 몇 개의 블루레이를 쓰는지 리턴

        if (cnt <= target) {
            right = mid - 1;
            ans = mid; //cnt == target일 때
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

/**
 * m개의 블루레이에 모든 기타 강의 동영상을 녹화할 때 블루레이 크기의 최소를 구하는 문제
 * -> 특정 블루레이 크기로 기타 강의 동영상을 차례로 녹화할 때, 총 블루레이 개수가 m개가 되는가?
 *
 * left: 가능한 블루레이의 최소 크기 (블루레이 최대 개수) -> 가장 긴 강의 길이값
 * right: 가능한 블루레이의 최대 크기 (블루레이 최소 개수) -> 모든 강의를 더한 길이값
 */

int main() {
    int n, m, left = 0, right = 0;

    //입력
    cin >> n >> m;
    vector<int> lesson(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> lesson[i];
        left = max(left, lesson[i]); //가장 긴 강의 길이값 찾기
        right += lesson[i]; //모든 강의 길이 더하기
    }

    //연산 & 출력
    cout << lowerSearch(lesson, left, right, m);

    return 0;
}