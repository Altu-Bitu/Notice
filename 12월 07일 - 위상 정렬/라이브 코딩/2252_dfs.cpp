#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<bool> visited;
vector<vector<int>> graph; //그래프 관계
stack<int> st; //위상정렬 순서가 역순으로 들어감

//위상정렬
void dfs(int node) {
    if (visited[node]) //이미 방문한 정점이라면
        return;

    visited[node] = true; //방문 체크
    for (int i = 0; i < graph[node].size(); i++)
        dfs(graph[node][i]);
    st.push(node); //더 이상 탐색할 정점이 없다면 현재 정점 삽입
}

int main() {
    int n, m, a, b;

    //입력
    cin >> n >> m;
    vector<int> indegree(n + 1, 0);
    graph.assign(n + 1, vector<int>(0));
    visited.assign(n + 1, false);
    while (m--) {
        cin >> a >> b; //a < b
        indegree[b]++;
        graph[a].push_back(b);
    }

    //연산
    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) //dfs 탐색 시작 정점
            dfs(i);
    }

    //출력
    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
    return 0;
}
