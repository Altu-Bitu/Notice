#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e5 * 2; //최대 N*N 칸을 지나게 됨

int dijkstra(int n, vector<vector<int>> &board) {
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int ans = 0;
    vector<vector<int>> dist(n, vector<int>(n, INF));
    priority_queue<pair<int, ci>, vector<pair<int, ci>>, greater<>> pq;

    //시작 위치 초기화
    dist[0][0] = board[0][0];
    pq.push(make_pair(dist[0][0], make_pair(0, 0)));

    while (!pq.empty()) {
        int weight = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();

        if (row == n - 1 && col == n - 1) { //제일 오른쪽 아래 칸 도착
            ans = weight;
            break;
        }
        if(weight > dist[row][col]) //이미 확인했던 좌표
            continue;
        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];
            if ((nr < 0) || (nr >= n) || (nc < 0) || (nc >= n)) //범위를 벗어난다면
                continue;

            int next_weight = weight + board[nr][nc]; //시작점으로부터 연결된 좌표까지의 거리
            if (dist[nr][nc] > next_weight) { //더 짧은 경로로 갈 수 있다면
                dist[nr][nc] = next_weight;
                pq.push({next_weight, {nr, nc}});
            }
        }
    }
    return ans;
}

/**
 * 상하좌우로 이동 가능 -> 연결됐다는 것
 * 시작 지점이 (0, 0)인 다익스트라
 */
int main() {
    int n, num = 1;

    while (true) {
        //입력
        cin >> n;
        if (n == 0)
            break;

        vector<vector<int>> board(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> board[i][j];
        }

        //연산 & 출력
        cout << "Problem " << num++ << ": " << dijkstra(n, board) << '\n';
    }
}