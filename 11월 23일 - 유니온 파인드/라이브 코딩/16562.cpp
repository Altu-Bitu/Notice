//
// Created by iw040 on 2021-11-23.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) //값이 음수면 루트 정점
        return node;
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
        return;
    if (parent[xp] > parent[yp]) //새로운 루트 xp
        parent[yp] = xp;
    else //새로운 루트 yp
        parent[xp] = yp;
}

int friendshipCost(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] < 0) //루트 정점이라면
            sum += -parent[i];
    }
    return sum;
}

int main() {
    int n, m, k, v, w, cost;

    //입력
    cin >> n >> m >> k;
    parent.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> cost;
        parent[i] = -cost; //루트 정점에 필요한 친구비(음수)를 저장
    }

    //연산
    while (m--) {
        cin >> v >> w;
        unionInput(v, w);
    }

    int ans = friendshipCost(n);

    //출력
    if (ans <= k)
        cout << ans;
    else
        cout << "Oh no";
}