#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> ci; //pair<int,int> 자료형을 ci 별칭으로 사용함을 정의

/**
 * 서류심사 혹은 면접심사 순위 기준으로 정렬해서 나머지 심사 순위 비교하며 푸는 문제
 * 본 풀이는 서류심사 순위를 기준으로 정렬한 풀이
 */

int cntEmploy(int n, vector<ci> rank) {
    /**
     * 서류심사가 1등인 0번 인덱스 사람은 무조건 합격이므로 1번 인덱스부터 검사
     * 현재 인덱스 사람은 서류심사 순위가 그 다음 인덱스 사람들보다 무조건 위
     * 따라서 그 전 사람들(서류심사가 현재 사람보다 높은)보다 면접심사가 높으면 합격
     */
    int ans = 1, first_rank = rank[0].second;
    for (int i = 1; i < n; i++) {
        //전 사람들 모두의 면접심사 순위보다 더 높은 경우
        if (first_rank > rank[i].second) {
            //가장 높은 면접심사 순위 계속 갱신해서 O(n) 으로 풀이
            first_rank = rank[i].second;
            ans++;
        }
    }
    return ans;
}

int main() {
    int t, n, ans;
    vector<ci> rank;

    //입력
    cin >> t;
    while (t--) {
        cin >> n;
        rank.assign(n, ci(0, 0));
        for (int i = 0; i < n; i++)
            cin >> rank[i].first >> rank[i].second; //first: 서류심사 순위, second: 면접심사 순위

        //연산
        //first값인 서류심사 순위가 높은 순서대로 정렬 (오름차순 정렬)
        //왼쪽값 기준 오름차순 정렬이 기본 정렬이므로 cmp함수 필요 없음
        sort(rank.begin(), rank.end());
        ans = cntEmploy(n, rank);

        //출력
        cout << ans << '\n';
    }
    return 0;
}