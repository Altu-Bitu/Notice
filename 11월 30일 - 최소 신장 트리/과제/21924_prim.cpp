#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 1e6 + 1;
typedef pair<int, int> ci;

long long prim(int v, int start, long long tot, vector<vector<ci>> &graph) {
    int cnt = 0; //검사한 정점 개수
    long long sum = 0;
    vector<int> dist(v + 1, INF); //각 정점까지의 비용
    vector<bool> visited(v + 1, false); //정점 방문 여부
    priority_queue<ci, vector<ci>, greater<>> pq;

    //초기화
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = pq.top().first; //간선 가중치
        int cur = pq.top().second; //현재 정점
        pq.pop();

        if (visited[cur]) //이미 확인했던 정점
            continue;
        cnt++; //확인한 정점 증가
        sum += cost; //MST 간선 가중치 총합
        visited[cur] = true; //방문 처리

        for (int i = 0; i < graph[cur].size(); i++) {
            int next_node = graph[cur][i].first;
            int next_cost = graph[cur][i].second;
            if (!visited[next_node] && next_cost < dist[next_node]) { //미방문 정점이면서 더 짧은 간선을 통해 갈 수 있다면
                dist[next_node] = next_cost;
                pq.push({next_cost, next_node});
            }
        }
    }
    if (cnt != v) //트리를 만들 수 없는 경우
        return -1;
    return tot - sum;
}

int main() {
    int n, m, a, b, c;
    long long tot = 0;

    //입력
    cin >> n >> m;
    vector<vector<ci>> graph(n + 1, vector<ci>(0));
    while (m--) { //무방향 그래프
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
        tot += c; //도로를 다 설치할 때 드는 비용
    }

    //연산 & 출력
    cout << prim(n, 1, tot, graph);
}