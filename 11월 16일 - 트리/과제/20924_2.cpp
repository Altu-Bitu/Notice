#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

//first: 기둥의 길이, second: 가장 긴 가지의 길이
ci bfs(int n, int r, vector<vector<ci>> &tree) {
    queue<int> q;
    vector<int> visited(n + 1, -1);
    int trunk_len = -1, max_branch = 0, len = 0;

    //루트 노드 초기화
    q.push(r);
    visited[r] = 0;
    if (tree[r].size() >= 2)
        trunk_len = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        len = visited[node];
        if (trunk_len != -1) //기둥의 길이가 존재한다면 -> 가장 긴 가지의 길이 갱신
            max_branch = max(max_branch, len);
        else if (tree[node].size() > 2) { //기가 노드 발견 -> 기둥의 길이 저장
            trunk_len = len;
            len = 0;
        }

        for (int i = 0; i < tree[node].size(); i++) {
            int next_node = tree[node][i].first;
            if (visited[next_node] != -1)
                continue;
            q.push(next_node);
            visited[next_node] = len + tree[node][i].second;
        }
    }
    if (trunk_len == -1) //리프 노드가 기가 노드일 경우
        trunk_len = len;
    return {trunk_len, max_branch};
}

/**
 * BFS 풀이
 *
 * visited: 방문 여부 + 길이 저장 (-1: 방문 안한 상태)
 *
 * 기가 노드: 3개 이상의 노드와 연결된 정점 (단, 루트 노드는 2개 이상(자식 2개) 연결된 경우 기가 노드에 해당)
 * 기둥: BFS 탐색을 이어나가다 기가 노드를 찾으면 지금까지 저장된 길이가 기둥의 길이
 * 가장 긴 가지의 길이: 기가 노드를 찾은 후부터 길이를 다시 더하며 가장 긴 가지 길이 계속 갱신
 */

int main() {
    int n, r, a, b, d;

    //입력
    cin >> n >> r;
    vector<vector<ci>> tree(n + 1, vector<ci>(0));
    for (int i = 0; i < n - 1; i++) { //무방향 그래프
        cin >> a >> b >> d;
        tree[a].emplace_back(b, d);
        tree[b].emplace_back(a, d);
    }

    //연산
    ci ans = bfs(n, r, tree);

    //출력
    cout << ans.first << ' ' << ans.second << '\n';
}