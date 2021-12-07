//
// Created by BaeSuA on 2021-12-07.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//위상정렬 + DP
int topologicalSort(int n, int w, vector<int> &delay, vector<int> &indegree, vector<vector<int>> &graph) {
    //vector<int> result;
    queue<int> q;
    vector<int> dp(n + 1, 0); //현재 건물(인덱스)을 짓기까지 걸린 최소 시간

    for (int i = 1; i <= n; i++) {
        dp[i] = delay[i]; //dp 배열 초기화
        if (!indegree[i]) //진입차수가 0이라면
            q.push(i);
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        //result.push_back(node); //현재 정점 순서에 삽입
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i];
            indegree[next_node]--; //연결된 정점의 진입차수를 1씩 감소
            if (!indegree[next_node]) //연결된 정점의 진입차수가 0이 되었다면
                q.push(next_node);

            //다음 정점의 최소 시간 계산 -> 이어진 전 정점(현재 정점) 중 가장 긴 시간의 건물을 선택
            dp[next_node] = max(dp[next_node], dp[node] + delay[next_node]);
        }
    }
    return dp[w];
}

int main() {
    int t, n, k, x, y, w;

    //입력
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> indegree(n + 1, 0); //진입차수
        vector<vector<int>> graph(n + 1, vector<int>(0)); //그래프
        vector<int> delay(n + 1, 0); //건설에 걸리는 시간
        for (int i = 1; i <= n; i++)
            cin >> delay[i];
        while (k--) {
            cin >> x >> y; //x -> y
            indegree[y]++;
            graph[x].push_back(y);
        }
        cin >> w; //승리하기 위해 건설해야 할 건물의 번호

        //연산 & 출력
        cout << topologicalSort(n, w, delay, indegree, graph) << '\n';
    }
    return 0;
}