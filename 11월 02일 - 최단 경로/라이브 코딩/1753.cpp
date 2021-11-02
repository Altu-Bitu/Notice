//
// Created by iw040 on 2021-11-02.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e5 * 2; //최대 V-1개의 간선을 지나게 됨

//다익스트라
vector<int> dijkstra(int vertex, int start, vector<vector<ci>> &graph) {
    vector<int> dist(vertex + 1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq; //first : 시작점으로부터의 거리, second : 정점

    //시작 위치 초기화
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (weight > dist[node]) //이미 확인했던 정점
            continue;
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first; //연결된 정점
            int next_weight = weight + graph[node][i].second; //시작점으로부터 연결된 정점까지의 거리
            if (dist[next_node] > next_weight) { //더 짧은 경로로 갈 수 있다면
                dist[next_node] = next_weight;
                pq.push({next_weight, next_node});
            }
        }
    }
    return dist;
}

int main() {
    int vertex, edge, k, u, v, w;

    //입력
    cin >> vertex >> edge >> k;
    vector<vector<ci>> graph(vertex + 1, vector<ci>(0)); //인접 리스트
    while (edge--) {
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w); //방향 그래프
    }

    //연산
    vector<int> ans = dijkstra(vertex, k, graph);

    //출력
    for (int i = 1; i <= vertex; i++) {
        if (ans[i] == INF)
            cout << "INF";
        else
            cout << ans[i];
        cout << '\n';
    }
}