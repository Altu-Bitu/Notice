//
// Created by iw040 on 2021-11-16.
//

#include <iostream>
#include <vector>

using namespace std;

bool is_tree;
vector<bool> visited;
vector<vector<int>> graph;

void dfs(int node, int parent) {
    if (visited[node]) { //이미 방문한 정점이라면 사이클이 발생한 것
        is_tree = false;
        return;
    }

    visited[node] = true; //방문 처리
    for (int i = 0; i < graph[node].size(); i++) {
        if (graph[node][i] != parent) //부모 정점이 아니라면
            dfs(graph[node][i], node);
    }
}

void printResult(int num, int cnt) {
    cout << "Case " << num;
    if (cnt == 0)
        cout << ": No trees.\n";
    else if (cnt == 1)
        cout << ": There is one tree.\n";
    else
        cout << ": A forest of " << cnt << " trees.\n";
}

int main() {
    int n, m, a, b, test_case = 0;

    while (true) {
        test_case++;

        //입력
        cin >> n >> m;
        if ((n == 0) && (m == 0)) //종료 조건
            break;
        visited.assign(n + 1, false);
        graph.assign(n + 1, vector<int>(0));
        while (m--) { //무방향 그래프
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        //연산
        int tree_cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (visited[i]) //이미 방문한 정점
                continue;
            is_tree = true;
            dfs(i, -1);
            if (is_tree) //트리가 맞다면
                tree_cnt++;
        }

        //출력
        printResult(test_case, tree_cnt);
    }
}