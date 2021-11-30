//
// Created by iw040 on 2021/11/30.
//

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

//kruskal
int kruskal(int v, priority_queue<tp, vector<tp>, greater<>> &pq) {
    int cnt = 0, sum = 0;

    while (cnt < v - 1) { //사용한 간선의 수가 v-1보다 작을 동안
        int weight = get<0>(pq.top());
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        pq.pop();

        if (unionInput(x, y)) { //유니온 했다면
            cnt++;
            sum += weight;
        }
    }
    return sum;
}

int main() {
    int v, e, a, b, c;
    priority_queue<tp, vector<tp>, greater<>> pq;

    //입력
    cin >> v >> e;
    parent.assign(v + 1, -1);
    while (e--) {
        cin >> a >> b >> c;
        pq.push({c, a, b});
    }

    //연산 & 출력
    cout << kruskal(v, pq);
}