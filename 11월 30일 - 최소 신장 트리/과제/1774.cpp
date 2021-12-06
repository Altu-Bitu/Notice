#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<double, double> ci;
typedef tuple<double, int, int> tp;

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

double kruskal(int v, priority_queue<tp, vector<tp>, greater<>> &pq) {
    int cnt = 0;
    double sum = 0;

    while (cnt < v - 1) { //사용한 간선의 수가 v-1보다 적을 동안
        double cost = get<0>(pq.top());
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());

        pq.pop();
        if (unionInput(x, y)) { //유니온 했다면
            cnt++; //사용된 간선 증가
            sum += cost; //간선의 가중치
        }
    }
    return sum;
}

/**
 * 4386번 : 별자리 만들기의 응용 문제
 * 이미 연결된 정점들이 존재한다는 것을 제외하고는 4386번과 동일
 *
 * 1. 임의의 두 별에 대한 거리(간선) 모두 구하기
 * 2. 이미 존재하는 통로들 표시
 *    !주의! 통로의 개수가 m개라면 v-m-1개의 간선만 더 추가하면 될까?
 *          이미 연결된 통로들도 사이클을 이룰 수 있기 때문에 유니온 연산을 하며 사이클 없이 연결된 간선만 세기
 * 3. 이미 연결된 통로의 수를 k개라고 하면 v-k-1개의 간선을 추가로 선택
 */
int main() {
    int n, m, a, b, v = 0;
    priority_queue<tp, vector<tp>, greater<>> pq;

    //입력
    cin >> n >> m;
    parent.assign(n + 1, -1);
    vector<ci> stars(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> stars[i].first >> stars[i].second;


    //연산
    //임의의 두 별에 대한 거리(간선) 모두 구하기
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            double xd = stars[i].first - stars[j].first;
            double yd = stars[i].second - stars[j].second;
            pq.push({sqrt(xd * xd + yd * yd), i, j});
        }
    }
    while (m--) {
        cin >> a >> b;
        if (unionInput(a, b)) //이미 연결된 통로
            v++;
    }

    //연산 & 출력
    cout << fixed;
    cout.precision(2);
    cout << kruskal(n - v, pq);
}