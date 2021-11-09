//
// Created by BaeSuA on 2021-11-09.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 1e5;

//역추적
vector<int> back(int x, vector<int> &path) { //x: k(도착지점)부터
    vector<int> result(0); //정답 경로
    while (x != -1) {
        result.push_back(x);
        x = path[x]; //다음 정점
    }
    return result;
}

int bfs(int n, int k, vector<int> &path) {
    vector<int> check(SIZE + 1, 0);
    queue<int> q; //큐에 좌푯값 저장
    int ans = 0; //최단 시간

    check[n] = 1; //시작 노드 방문 체크
    q.push(n); //시작 노드 초기화
    while (!q.empty()) {
        int x = q.front(); //현재 탐색하려는 위치
        q.pop();

        if (x == k) { //동생 찾으면 탐색 종료.
            ans = check[x] - 1; //시작 노드 초기화를 1로 했기 때문에 1을 빼줌
            break;
        }

        vector<int> child = {x - 1, x + 1, x * 2}; //자식노드
        for (int i = 0; i < 3; i++) {
            if (child[i] >= 0 && child[i] <= SIZE && !check[child[i]]) { //범위 내에 있고, 첫 방문이라면
                check[child[i]] = check[x] + 1;
                path[child[i]] = x; //경로 저장
                q.push(child[i]);
            }
        }
    }
    return ans;
}

/**
 * 최단거리(BFS) 역추적
 * - 기본 문제: 숨바꼭질
 */

int main() {
    vector<int> path(SIZE + 1, -1); //경로 저장 벡터
    int n, k;

    //입력
    cin >> n >> k;

    //연산
    int ans = bfs(n, k, path);
    vector<int> result = back(k, path);

    //출력
    cout << ans << '\n';
    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i] << ' ';
    return 0;
}