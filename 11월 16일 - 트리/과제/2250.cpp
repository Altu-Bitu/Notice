#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int INF = 1e4 + 1;

map<int, pair<int, int>> tree;
vector<int> level_left, level_right;
int width;

//너비가 가장 넓은 레벨 구하는 함수
pair<int, int> findMaxWidth(int level) {
    int ans_width = 1, ans_level = 1;
    while (level_right[++level] != 0) {
        int level_width = level_right[level] - level_left[level] + 1;
        if (ans_width < level_width) {
            ans_width = level_width;
            ans_level = level;
        }
    }
    return {ans_level, ans_width};
}

//중위 순회를 하며 열 번호 구하는 함수
void inorder(int node, int level) {
    if (node == -1)
        return;

    inorder(tree[node].first, level + 1);
    level_left[level] = min(level_left[level], width);
    level_right[level] = max(level_right[level], width++);
    inorder(tree[node].second, level + 1);
}

//루트 노드 찾는 함수
int findRoot(int n, vector<int> &node_cnt) {
    for (int i = 1; i <= n; i++)
        if (node_cnt[i] == 1)
            return i;
}

/**
 * tree: key 값을 부모 노드로 해서 value에 왼쪽, 오른쪽 자식노드를 저장
 * level_left: 레벨을 인덱스로 해당 레벨의 가장 왼쪽 노드의 열 번호 저장
 * level_right: 레벨을 인덱스로 해당 레벨의 가장 오른쪽 노드의 열 번호 저장
 *
 * 루트 노드가 1이 아닐 수 있으므로 루트 노드를 찾아주고 시작해야 함 -> 부모 노드가 없으면 루트 노드 -> 입력으로 한 번 주어진 경우 루트 노드
 * 각 노드의 열 번호는 중위 순회를 했을 때, 출력 순서와 같음 -> 이를 이용해서 중위 순회를 하며 가장 작은 열 번호와 큰 열 번호를 구함
 */

int main() {
    int n, p, l, r;

    //입력
    cin >> n;
    level_left.assign(n + 1, INF);
    level_right.assign(n + 1, 0);
    vector<int> node_cnt(n + 1, 0); //루트 노드 찾기 위해서 카운트 저장
    for (int i = 0; i < n; i++) {
        cin >> p >> l >> r;
        node_cnt[p]++;
        if (l != -1)
            node_cnt[l]++;
        if (r != -1)
            node_cnt[r]++;
        tree[p] = make_pair(l, r);
    }

    //연산
    int root = findRoot(n, node_cnt);
    inorder(root, 1);
    pair<int, int> ans = findMaxWidth(0);

    //출력
    cout << ans.first << ' ' << ans.second << '\n';
    return 0;
}