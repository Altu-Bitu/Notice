//
// Created by BaeSuA on 2021-10-01.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

bool cmp(const ci &a, const ci &b) {
    if (a.second != b.second)
        return a.second < b.second; //회의가 끝나는 시간이 빠른 순으로 -> 그래야 최대한 많은 회의 가능
    return a.first < b.first; //끝나는 시간이 같다면, 시작 시간이 빠른 순으로 (회의 시작과 끝이 같을 수 있기 때문)
}

int maxMeeting(int n, vector<ci> meeting) {
    int end = meeting[0].second; //처음 회의 끝나는 시간
    int cnt = 1; //회의의 최대 개수
    for (int i = 1; i < n; i++) {
        if (end <= meeting[i].first) { //현재 회의실에 끝나는 시간보다 시작 시간이 같거나 크다면
            cnt++;
            end = meeting[i].second; //끝나는 회의 갱신
        }
    }

    return cnt;
}

int main() {
    int n;

    //입력
    cin >> n;
    vector<ci> meeting(n, ci(0, 0));
    for (int i = 0; i < n; i++)
        cin >> meeting[i].first >> meeting[i].second;

    //연산
    sort(meeting.begin(), meeting.end(), cmp);

    //연산 & 출력
    cout << maxMeeting(n, meeting);

    return 0;
}