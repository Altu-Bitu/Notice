#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1e9;

vector<vector<int>> matrix;
int ans = INF;

//특정 경로에 대해 유효한 경로인지 확인하고, 순회 비용을 계산하는 함수
int calcCost(int n, vector<int> visited) {
    int sum = 0;
    visited.push_back(visited[0]); //시작 도시로 되돌아오기 위해 삽입

    for (int i = 1; i <= n; i++) {
        int before_city = visited[i - 1], cur_city = visited[i];
        if (!matrix[before_city][cur_city]) //길이 없다면 이 경로는 불가능
            return INF;
        sum += matrix[before_city][cur_city]; //순회 비용
    }
    return sum;
}

/**
 * permutation 풀이 (300ms) (2529_2.cpp 주석을 먼저 봐주세요)
 *
 * 모든 도시를 한 번씩 방문 하는 모든 경우의 수를 탐색
 * 만약 탐색 가능한 경로라면 최소 비용 갱신
 *
 * 도시가 3개일 때 방문하는 모든 경우의 수
 * (0->1->2->0), (0->2->1->0), (1->0->2->1), (1->2->0->1), (2->0->1->2), (2->1->0->2)
 */
int main() {
    int n;
    vector<int> visited;

    //입력
    cin >> n;
    visited.assign(n, 0);
    matrix.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
        visited[i] = i;
    }

    //연산
    do {
        ans = min(ans, calcCost(n, visited));
    } while (next_permutation(visited.begin(), visited.end()));

    //출력
    cout << ans;
}