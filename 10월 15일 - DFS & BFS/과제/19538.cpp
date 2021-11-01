#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(vector<vector<int>> &people, vector<int> &init, int n) {
    vector<int> believer(n + 1, 0); //주변인들이 몇 명 믿는지
    vector<int> ans(n + 1, -1); //몇 분 후에 믿는지
    queue<int> q;

    //시작 정점 초기화
    for (int i = 0; i < init.size(); i++) {
        ans[init[i]] = 0;
        q.push(init[i]);
    }

    while (!q.empty()) {
        int v = q.front(); //현재 사람
        int t = ans[v]; //루머 믿은 시간
        q.pop();

        for (int i = 0; i < people[v].size(); i++) {
            int next = people[v][i];
            believer[next]++; //next의 주변에서 루머를 믿는 사람 증가
            if (ans[next] != -1) //이미 루머를 믿는 다면
                continue;
            if ((people[next].size() + 1) / 2 <= believer[next]) { //주변인들 중 절반 이상이 루머를 믿으면
                ans[next] = t + 1;
                q.push(next);
            }
        }
    }
    return ans;
}

/**
 * 주변인들이 얼마나 믿는지를 배열을 통해 관리해야 함
 * 방문 체크를 탐색할 때 바로 하는 게 아니라, 루머를 믿게 될 경우 하는 게 중요 (루머를 몇 분 후에 믿는지를 저장하는 배열로 관리)
 */

int main() {
    int n, m, input;

    //루머 퍼뜨리는 관계 입력
    cin >> n;
    vector<vector<int>> people(n + 1, vector<int>());
    for (int i = 1; i <= n; i++) {
        while (true) {
            cin >> input;
            if (!input)
                break;
            people[i].push_back(input);
        }
    }

    //최초 유포자 입력
    cin >> m;
    vector<int> init(m, 0);
    for (int i = 0; i < m; i++)
        cin >> init[i];

    //연산
    vector<int> ans = bfs(people, init, n);

    //출력
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';

    return 0;
} 