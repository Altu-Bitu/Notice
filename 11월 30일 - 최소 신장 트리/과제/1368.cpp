#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 1e5 + 1;

int prim(int size, int start, vector<vector<int>> &graph) {
    int sum = 0;
    vector<int> dist(size, INF); //각 논까지의 비용
    vector<bool> visited(size, false); //논 방문 여부
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    //초기화
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = pq.top().first; //간선 가중치
        int cur = pq.top().second; //현재 논
        pq.pop();

        if (visited[cur]) //이미 확인했던 정점
            continue;
        sum += cost; //MST 간선 가중치 총합
        visited[cur] = true; //방문 처리

        for (int i = 0; i < size; i++) {
            if (!visited[i] && graph[cur][i] < dist[i]) { //미방문 정점이면서 더 짧은 간선을 통해 갈 수 있다면
                dist[i] = graph[cur][i];
                pq.push({dist[i], i});
            }
        }
    }
    return sum;
}

/**
 * 각 논들 사이의 간선도 고려하고, 우물을 파는 경우도 고려? -> 복잡
 * 논에 추가로 모든 우물과 연결되는 수원이 있다고 가정!
 * ->직접 논에 우물을 파는 경우는 수원과 각 논 사이의 간선 가중치라고 할 수 있음
 * 
 * 0 2 2 2 5
 * 2 0 3 3 4
 * 2 3 0 4 4
 * 2 3 4 0 3
 * 5 4 4 3 0
 * 
 * 인덱스 0 ~ n-1은 논, 인덱스 n은 수원
 * 1개 이상의 논은 반드시 직접 우물을 파야 하므로 수원(n)에서 시작하는 프림 알고리즘
 */
int main() {
    int n, w;

    cin >> n;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) { //수원으로부터 물을 끌어오는 비용
        cin >> w;
        graph[i][n] = graph[n][i] = w;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> graph[i][j]; //논들 사이에서 물을 끌어오는 비용
    }

    cout << prim(n + 1, n, graph); //수원에서 시작하는 프림 알고리즘
}