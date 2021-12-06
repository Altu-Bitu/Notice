#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;
typedef tuple<int, int, int> tp;

vector<int> parent;

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) //값이 음수면 루트 정점
        return node;
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
bool unionInput(int x, int y) {
    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
        return false;
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp];
        parent[yp] = xp;
    } else { //새로운 루트 yp
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
    return true;
}

long long kruskal(int v, long long tot, priority_queue<tp, vector<tp>, greater<>> &pq) {
    int cnt = 0;
    long long sum = 0;

    while (cnt < v - 1) { //사용한 간선의 수가 v-1보다 적을 동안
        if (pq.empty()) //사용한 간선이 v-1개가 안됐는데 더 이상 검사할 간선이 없다면
            return -1;

        int cost = get<0>(pq.top());
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());

        pq.pop();
        if (unionInput(x, y)) { //유니온 했다면
            cnt++;
            sum += cost;
        }
    }
    return tot - sum;
}

/**
 * 기본 MST 문제에서 트리를 만들 수 없는 경우(간선이 N-1개가 아닌 경우)를 고려한 문제
 *
 * 최대 비용의 범위가 약 10^6 x 10^5 이므로 long long 자료형을 써야 함
 */

int main() {
    int n, m, a, b, c;
    long long tot = 0;
    priority_queue<tp, vector<tp>, greater<>> pq;

    //입력
    cin >> n >> m;
    parent.assign(n + 1, -1);
    while (m--) {
        cin >> a >> b >> c;
        pq.push({c, a, b});
        tot += c; //도로를 다 설치할 때 드는 비용
    }

    //연산 & 출력
    cout << kruskal(n, tot, pq);
}