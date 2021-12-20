#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//위상정렬
vector<int> topologicalSort(int n, vector<int> &indegree, vector<vector<int>> &graph) {
    vector<int> result;
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) //진입차수가 0이라면
            q.push(i);
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        result.push_back(node); //현재 정점 순서에 삽입
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i];
            indegree[next_node]--; //연결된 정점의 진입차수를 1씩 감소
            if (!indegree[next_node]) //연결된 정점의 진입차수가 0이 되었다면
                q.push(next_node);
        }
    }
    return result;
}

/**
 * 기본적인 위상 정렬 문제
 * 현재 가수와 바로 전 가수 사이의 선후관계를 정의
 * 순서를 정하는 것이 불가능한 경우(위상정렬을 할 수 없는 경우)는 모든 정점을 탐색하지 못한 경우
 */

int main() {
    int n, m, cnt, prev, cur;

    //입력
    cin >> n >> m;
    vector<int> indegree(n + 1, 0);
    vector<vector<int>> graph(n + 1, vector<int>(0));
    while (m--) {
        cin >> cnt; //담당 가수의 수
        cin >> prev; //처음 가수 입력
        while (--cnt) { //선후관계 정의
            cin >> cur;
            indegree[cur]++;
            graph[prev].push_back(cur);
            prev = cur;
        }
    }

    //연산
    vector<int> result = topologicalSort(n, indegree, graph);

    //출력
    if (result.size() != n) { //순서를 정하는 것이 불가한 경우
        cout << "0\n";
        return 0;
    }
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << '\n';
}