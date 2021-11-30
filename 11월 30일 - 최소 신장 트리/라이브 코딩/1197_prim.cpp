//
// Created by iw040 on 2021/11/30.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 1e6;
typedef pair<int, int> ci;

int prim(int v, int start, vector<vector<ci>> &graph) {
    int sum = 0;
    //vector<int> dist(v + 1, INF); //각 정점까지의 비용 (없어도 상관없으나, 사용하면 메모리를 좀 더 아낄 수 있음)
    vector<bool> visited(v + 1, false); //정점 방문 여부 (다익스트라와 달리 프림에선 필요!)
    priority_queue<ci, vector<ci>, greater<>> pq;

    //초기화
    //dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int weight = pq.top().first; //간선 가중치
        int node = pq.top().second; //현재 정점
        pq.pop();

        if (visited[node]) //이미 확인했던 정점
            continue;
        sum += weight; //MST 간선 가중치 총 합에 더해줌
        visited[node] = true; //방문 처리

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            int next_weight = graph[node][i].second;
            if (!visited[next_node]) { //미방문 정점(이면서 더 짧은 간선을 통해 갈 수 있다면)
                //dist[next_node] = next_weight;
                pq.push({next_weight, next_node});
            }
        }
    }
    return sum;
}

int main() {
    int v, e, a, b, c;

    //입력
    cin >> v >> e;
    vector<vector<ci>> graph(v + 1, vector<ci>(0));
    while (e--) { //무방향 그래프
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    //연산 & 출력
    cout << prim(v, 1, graph);
}