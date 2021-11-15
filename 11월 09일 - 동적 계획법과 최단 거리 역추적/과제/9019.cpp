#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, char> ci;
const int SIZE = 10000;

//역추적
string back(int x, vector<ci> &path) { //x = B부터 역추적 시작
    string ans = "";
    while (path[x].first != -1) {
        ans += path[x].second;
        x = path[x].first;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

//bfs
void bfs(int a, int b, vector<ci> &path) {
    vector<bool> visited(SIZE, false);
    queue<int> q;

    q.push(a); //시작 노드 초기화
    visited[a] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == b) //B를 만들었다면 즉시 탐색 종료
            break;

        vector<ci> child = {{cur * 2 % SIZE,                   'D'},
                            {(cur - 1 + SIZE) % SIZE,          'S'},
                            {(cur * 10 % SIZE) + (cur / 1000), 'L'},
                            {(cur % 10 * 1000) + (cur / 10),   'R'}};
        for (int i = 0; i < 4; i++) {
            int next = child[i].first;
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
                path[next] = ci(cur, child[i].second); //자식 노드에 부모 노드(경로)와 명령어 저장
            }
        }
    }
}

/**
 * path: 경로와 수행한 명령어(D, S, L, R)를 저장
 *
 * 각 명령어의 수행 결과를 사칙연산으로 나타낼 수 있음 (cur: 현재 수, SIZE = 10,000)
 * D: cur * 2 % SIZE
 * S: (cur - 1 + SIZE) % SIZE (cur이 0일 경우를 처리하기 위해)
 * L: (cur * 10 % SIZE) + (cur / 1000)
 * R: (cur % 10 * 1000) + (cur / 10)
 *
 * 따라서 위의 연산을 적용한 값들을 자식노드로 하여 bfs 탐색 진행
 * 앞서 구한 path값을 따라 B인덱스부터 역추적 시작
 */

int main() {
    int t, a, b;

    //입력 & 연산 & 출력
    cin >> t;
    while (t--) {
        cin >> a >> b;
        vector<ci> path(SIZE, {-1, ' '}); //first: 경로, second: 명령어
        bfs(a, b, path);
        cout << back(b, path) << '\n';
    }
    return 0;
}