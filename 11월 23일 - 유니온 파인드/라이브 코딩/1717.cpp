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
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp];
        parent[yp] = xp;
    } else { //새로운 루트 yp
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, cmd, a, b;

    //입력
    cin >> n >> m;
    parent.assign(n + 1, -1);
    while (m--) {
        cin >> cmd >> a >> b;

        //연산
        if (cmd == 0) { //유니온
            unionInput(a, b);
        }
        if (cmd == 1) { //파인드
            if (findParent(a) == findParent(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}