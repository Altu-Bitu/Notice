//
// Created by iw040 on 2021-11-23.
//

#include <iostream>
#include <vector>

using namespace std;

vector<bool> cycle;
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

    if (xp == yp) { //같은 집합에 있다면 유니온 할 수 없음
        cycle[xp] = true;
        return;
    }
    if (cycle[xp] || cycle[yp]) //둘 중 하나라도 사이클이 있으면 표시
        cycle[xp] = cycle[yp] = true;
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp];
        parent[yp] = xp;
    } else { //새로운 루트 yp
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
}

int cntTree(int n) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] < 0 && !cycle[i]) //루트 정점인데 사이클도 없을 때
            cnt++;
    }
    return cnt;
}

void printResult(int num, int cnt) {
    cout << "Case " << num;
    if (cnt == 0)
        cout << ": No trees.\n";
    else if (cnt == 1)
        cout << ": There is one tree.\n";
    else
        cout << ": A forest of " << cnt << " trees.\n";
}

int main() {
    int n, m, a, b, test_case = 0;

    while (true) {
        test_case++;

        //입력
        cin >> n >> m;
        if (n == 0 && m == 0) //종료 조건
            break;
        parent.assign(n + 1, -1);
        cycle.assign(n + 1, false);
        while (m--) { //무방향 그래프
            cin >> a >> b;
            unionInput(a, b);
        }

        //연산
        int tree_cnt = cntTree(n);

        //출력
        printResult(test_case, tree_cnt);
    }
}