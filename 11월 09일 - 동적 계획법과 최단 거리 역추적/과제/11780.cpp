#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e7; //최대 n-1개의 간선을 지나게 됨

//역추적
vector<int> back(int s, int x, vector<vector<int>> &path) { //x: 도착점부터
    vector<int> result(0);
    while (x != 0) {
        result.push_back(x);
        x = path[s][x]; //다음 경로
    }
    return result;
}

//모든 (i, j)쌍의 역추적 결과값
vector<vector<int>> allPath(int n, vector<vector<int>> &path) {
    vector<vector<int>> ans(n * n);
    for (int i = 1; i <= n; i++) { //시작점(i)
        for (int j = 1; j <= n; j++) { //도착점(j)
            if (!path[i][j])
                continue;
            vector<int> result = back(i, j, path);
            ans[(i - 1) * n + (j - 1)] = result;
        }
    }
    return ans;
}

//플로이드-워셜
void floydWarshall(int n, vector<vector<int>> &graph, vector<vector<int>> &path) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int new_dist = graph[i][k] + graph[k][j]; //중간에 k를 거쳐서 i에서 j로 감
                if (new_dist < graph[i][j]) { //i->k->j가 i->j보다 빠른 경로라면
                    graph[i][j] = new_dist;
                    path[i][j] = path[k][j]; //경로(가장 마지막 정점) 저장
                }
            }
        }
    }
}

/**
 * graph: 플로이드-워셜 결과 행렬 그래프
 * path: 경료표. i->k->j로 갈 때 거치는 가장 마지막 정점. 즉, k와 j의 경로에 저장된 정점 <=> path[i][j] = path[k][j]
 * ans: 모든 (i, j)쌍의 역추적 결과값 저장
 *
 * 1. i->j의 중간 경로를 i로 초기화
 * 2. i->k->j가 i->j보다 짧다면 i->j의 중간 경로를 k->j의 중간 경로(path[k][j])로 갱신
 *    k로 갱신하는 게 아니라 path[k][j]로 갱신하는 이유는?
 *    만약 k->j의 경로가 k->t->j라면 최종 경로는 i->k->t->j
 *    바로 k로 갱신하면 t를 놓치고, 이러면 역추적을 할 수 없기 때문에 항상 j의 바로 전 경로를 저장해야 함
 */

int main() {
    int n, m, a, b, c;

    //입력
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    vector<vector<int>> path(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) //자기 자신으로 가는 경로 초기화
        graph[i][i] = 0;

    while (m--) {
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c); //단방향 그래프, 중복 간선 들어올 수 있음
        path[a][b] = a; //경로 초기화
    }

    //연산
    floydWarshall(n, graph, path);
    vector<vector<int>> ans = allPath(n, path);

    //출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << ((graph[i][j] == INF) ? 0 : graph[i][j]) << ' ';
        cout << '\n';
    }
    for (int i = 0; i < ans.size(); i++) {
        int size = ans[i].size();
        cout << size << ' ';
        for (int j = size - 1; j >= 0; j--)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}