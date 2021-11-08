#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e5; //최대 n-1개의 간선을 지나게 됨

vector<int> dijkstra(int n, int start, vector<vector<ci>> &graph) {
    vector<int> dist(n + 1, INF); //정점까지의 최단 시간 저장 배열
    priority_queue<ci, vector<ci>, greater<>> pq; //first : 시작점으로부터 소요시간, second : 정점

    //시작 위치 초기화
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int t = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (t > dist[node]) //이미 더 짧은 경로가 존재한다면
            continue;

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first; //연결된 정점
            int next_t = t + graph[node][i].second; //시작점으로부터 연결된 정점까지의 소요시간
            if (dist[next_node] > next_t) { //더 짧은 경로로 갈 수 있다면
                dist[next_node] = next_t;
                pq.push({next_t, next_node});
            }
        }
    }
    return dist;
}

/**
 * 1. 각 학생들이 X를 가는 데 걸리는 최단 시간 (i -> x)
 * 2. X에서 다시 돌아오는 데 걸리는 최단 시간 (x -> i)
 *
 * 우선 단방향 그래프이므로 위의 2개 값은 다를 수 있어 따로 구해주어야 함
 * 2번은 시작점이 X인 다익스트라로 무난히 구현
 * 1번은 역뱡향 그래프에서 시작점이 X인 다익스트라로 구현 -> 역방향을 다시 원상태로 돌리면 결국 도착점이 X가 됨 (4ms)
 *
 * 해당 문제는 N이 크지 않아 1번도 시작점이 i인 다익스트라를 N번 또는 1번 2번을 통틀어 조금 더 효율적인 플로이드-워셜로 구현 가능 (220ms)
 */

int main() {
    int n, m, x, a, b, c, ans = 0;

    //입력
    cin >> n >> m >> x;
    vector<vector<ci>> graph(n + 1, vector<ci>());
    vector<vector<ci>> rev_graph(n + 1, vector<ci>()); //역방향 그래프
    while (m--) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c}); //단방향
        rev_graph[b].push_back({a, c}); //역방향
    }

    //연산
    vector<int> dist_go = dijkstra(n, x, rev_graph); //역방향 그래프에서 시작점이 x인 모든 정점의 최단 시간
    vector<int> dist_back = dijkstra(n, x, graph); //시작점이 x인 모든 정점의 최단 시간
    for (int i = 1; i <= n; i++)
        ans = max(dist_go[i] + dist_back[i], ans);

    //출력
    cout << ans << '\n';
    return 0;
}