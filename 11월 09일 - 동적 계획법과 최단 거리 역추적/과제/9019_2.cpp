#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, string> ci;
const int SIZE = 10000;

string bfs(int a, int b) {
    vector<bool> visited(SIZE, false);
    queue<ci> q;

    q.push(ci(a, "")); //시작 노드 초기화
    visited[a] = true;
    while (!q.empty()) {
        int cur = q.front().first;
        string cur_path = q.front().second;
        q.pop();

        if (cur == b) //B를 만들었다면 탐색 종료
            return cur_path;

        int next = cur * 2 % SIZE;
        if (!visited[next]) {
            q.push(ci(next, cur_path + "D"));
            visited[next] = true;
        }
        next = (cur - 1 + SIZE) % SIZE;
        if (!visited[next]) {
            q.push(ci(next, cur_path + "S"));
            visited[next] = true;
        }
        next = (cur * 10 % SIZE) + (cur / 1000);
        if (!visited[next]) {
            q.push(ci(next, cur_path + "L"));
            visited[next] = true;
        }
        next = (cur % 10 * 1000) + (cur / 10);
        if (!visited[next]) {
            q.push(ci(next, cur_path + "R"));
            visited[next] = true;
        }
    }
}

/**
 * 기본 풀이 설명은 9019.cpp 주석 참고
 *
 * 큐에 경로를 바로 저장하며 푸는 풀이
 * -> 따라서 역추적 과정이 필요 없음
 *
 * 배열 풀이와 다르게 자식 노드 탐색을 if문 4개로 분리하는 이유
 * -> 자식 노드를 저장하는 벡터 선언 시 소요되는 시간 때문에 벡터 + for 문을 해당 풀이에서 사용하면 시간초과
 */

int main() {
    int t, a, b;

    //입력 & 연산 & 출력
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << bfs(a, b) << '\n';
    }
    return 0;
}