//
// Created by BaeSuA on 2021-10-15.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<bool>> adj_matrix; //인접행렬
vector<vector<int>> adj_list; //인접리스트

vector<bool> visited_recur;

//DFS (재귀함수)
//노드가 작은 순으로 탐색해야 하는 문제이므로 재귀함수가 더 효율적
void dfsRecur(int v) {
    if (visited_recur[v]) //이미 방문한 노드라면
        return;

    visited_recur[v] = true; //방문 체크
    cout << v << ' ';

    for (int i = 0; i < adj_list[v].size(); i++)
        dfsRecur(adj_list[v][i]);
}

//DFS : 깊이 우선 탐색
vector<int> dfs(int n, int v) {
    stack<int> st;
    vector<bool> visited(n + 1, false); //방문 노드 체크
    vector<int> result; //탐색순으로 노드 저장

    st.push(v); //처음 탐색 노드 삽입
    visited[v] = true; //방문 체크
    result.push_back(v);

    //탐색 시작
    while (!st.empty()) {
        int node = st.top(); //현재 탐색하려는 노드
        bool check = false; //연결 노드 존재 여부
        //인접행렬로 검사
        for (int i = 1; i <= n; i++) { //모든 노드에 대해
            if (adj_matrix[node][i] && !visited[i]) { //연결이 되어 있고, 처음 방문이라면
                check = true;
                visited[i] = true; //방문 체크
                st.push(i); //앞으로 탐색해야 할 노드이므로 스택에 삽입
                result.push_back(i); //탐색 노드 바로 삽입
                break; //이 문제에선 작은 노드부터 방문해야 하므로 바로 break
            }
        }
        /*
        //인접리스트로 검사
        for (int i = 0; i < adj_list[node].size(); i++) { //연결된 노드만
            if (!visited[adj_list[node][i]]) { //이미 연결된 노드 정보만 있으므로, 방문 체크만!
                check = true;
                visited[adj_list[node][i]] = true;
                st.push(adj_list[node][i]);
                result.push_back(adj_list[node][i]); //탐색 노드 바로 삽입
                break;
            }
        }
        */
        if (!check) //더 이상 연결 노드가 없다면, 원래 DFS라면 앞에서 꺼내온 순간 바로 pop()해야함
            st.pop();
    }

    return result;
}

//BFS : 너비 우선 탐색
vector<int> bfs(int n, int v) {
    queue<int> q;
    vector<bool> visited(n + 1, false); //방문 노드 체크
    vector<int> result; //탐색 순으로 정점 저장

    q.push(v); //처음 탐색 노드 삽입
    visited[v] = true; //방문 체크

    //탐색 시작
    while (!q.empty()) {
        int node = q.front(); //현재 탐색하려는 노드
        q.pop();
        result.push_back(node);
        //인접행렬로 검사
        for (int i = 1; i <= n; i++) { //모든 노드에 대해
            if (adj_matrix[node][i] && !visited[i]) { //연결이 되어 있고, 처음 방문이라면
                visited[i] = true; //방문 체크
                q.push(i); //앞으로 탐색해야할 노드이므로 큐에 삽입
            }
        }
        /*
        //인접리스트로 검사
        for (int i = 0; i < adj_list[node].size(); i++) { //연결된 노드만
            if (!visited[adj_list[node][i]]) { //이미 연결된 노드 정보만 있으므로, 방문 체크만!
                visited[adj_list[node][i]] = true;
                q.push(adj_list[node][i]);
            }
        }
        */
    }

    return result;

}

int main() {
    int n, m, v, a, b; //정점(node) 개수, 간선(edge) 개수, 시작 정점, 간선 정보(a, b)
    vector<vector<int>> result(2, vector<int>()); //결과 저장 배열

    //입력
    cin >> n >> m >> v;
    adj_matrix.assign(n + 1, vector<bool>(n + 1, false));
    adj_list.assign(n + 1, vector<int>());
    while (m--) {
        cin >> a >> b;
        //인접행렬
        adj_matrix[a][b] = adj_matrix[b][a] = true;
        //인접리스트
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    //인접리스트 구현 시, 노드 번호가 작은 것부터 방문하기 위해 정렬해야 함
    for (int i = 1; i <= n; i++)
        sort(adj_list[i].begin(), adj_list[i].end());

    //DFS - stack
    //result[0] = dfs(n, v);
    //DFS - 재귀함수
    visited_recur.assign(n + 1, false);
    dfsRecur(v);
    //BFS - queue
    result[1] = bfs(n, v);

    //출력
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}