#include <iostream>
#include <vector>

using namespace std;

//단절점, 단절선 파악 함수
string isTrue(int t, int k, vector<vector<int>> &tree) {
    if (t == 2)
        return "yes";
    if (tree[k].size() >= 2)
        return "yes";
    return "no";
}

/**
 * 부모 노드를 알 수 없기에 트리를 양방향 그래프로 저장
 * 단절점: 트리는 모든 정점이 연결되어 있고, 싸이클이 존재하지 않기 때문에 연결된 간선이 2개 이상이면 단절점
 * 단절선: 트리는 모든 정점이 연결되어 있고, 싸이클이 존재하지 않기 때문에 모든 간선이 단절선
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b, q, t, k;

    //입력
    cin >> n;
    vector<vector<int>> tree(n + 1, vector<int>(0));
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    cin >> q;
    while (q--) {
        cin >> t >> k;
        cout << isTrue(t, k, tree) << '\n';
    }
    return 0;
}