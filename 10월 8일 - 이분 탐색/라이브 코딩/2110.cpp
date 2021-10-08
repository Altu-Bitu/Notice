//
// Created by iw040 on 2021-10-08.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> house;

//가장 인접한 두 공유기 사이의 거리가 dist이도록 공유기를 설치했을 때, 설치된 공유기 숫자
int router(int dist) {
    //첫번째 집에 무조건 공유기 설치
    int cnt = 1;
    int pos = house[0];

    for (int i = 1; i < house.size(); i++) {
        if (house[i] - pos < dist) //가장 가까운 집과의 거리가 dist 이상이어야 설치 가능
            continue;
        //i번째 집에 공유기 설치
        cnt++;
        pos = house[i];
    }
    return cnt; //설치된 공유기 수
}

//가능한 최대 거리 중 가장 큰 값(=upper bound)
int upperSearch(int left, int right, int target) {
    int ans = 0;
    while (left <= right) {
        //가장 인접한 두 공유기 사이의 거리가 mid일 때, 공유기를 최대 몇 개 설치할 수 있는가?
        int mid = (left + right) / 2;
        int installed = router(mid);

        if (installed < target) //mid의 거리로는 target만큼의 공유기를 설치할 수 없음 -> 거리를 줄여야
            right = mid - 1;
        else if (installed >= target) { //mid의 거리로는 target만큼의 공유기를 설치할 수 있음 -> 거리를 늘려보자
            ans = mid; //현재의 mid값 저장. 최종 갱신되는 값은 upper bound
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, c;

    //입력
    cin >> n >> c;
    house.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> house[i];

    //연산
    sort(house.begin(), house.end());

    //연산 & 출력
    //공유기 사이의 최단 거리 (left) : 1
    //공유기 사이의 최장 거리 (right) : 가장 멀리 있는 두 집 사이의 거리
    cout << upperSearch(1, house[n - 1] - house[0], c);
}