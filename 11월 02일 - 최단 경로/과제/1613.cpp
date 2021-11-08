#include <iostream>
#include <vector>

using namespace std;

void floydWarshall(int n, vector<vector<bool>> &graph) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][k] && graph[k][j]) //i->k, k->j 전후관계 있는 경우
                    graph[i][j] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, s, a, b;

    //입력
    cin >> n >> k;
    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));
    while (k--) {
        cin >> a >> b;
        graph[a][b] = true; //전후관계 -> 단방향 그래프
    }

    //연산
    floydWarshall(n, graph);

    //입력 & 출력
    cin >> s;
    while (s--) {
        cin >> a >> b;
        if (graph[a][b])
            cout << "-1";
        else if (graph[b][a])
            cout << "1";
        else
            cout << "0";
        cout << '\n';
    }
    return 0;
}