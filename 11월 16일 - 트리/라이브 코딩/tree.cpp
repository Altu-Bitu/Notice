//
// Created by iw040 on 2021-11-16.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;

//트리의 정점 수
int nodeCnt(int node) {
    int cnt = 1;
    for (int i = 0; i < tree[node].size(); i++)
        cnt += nodeCnt(tree[node][i]);
    return cnt;
}

//리프 노드의 수
int leafCnt(int node) {
    if (tree[node].empty())
        return 1;

    int cnt = 0;
    for (int i = 0; i < tree[node].size(); i++)
        cnt += leafCnt(tree[node][i]);
    return cnt;
}

//트리의 높이
int treeHeight(int node) {
    int height = 0;
    for (int i = 0; i < tree[node].size(); i++)
        height = max(height, treeHeight(tree[node][i]));
    return height + 1;
}

int main() {
    //입력
    tree.assign(6, vector<int>(0));
    tree[1] = {2, 3, 4};
    tree[4] = {5};

    //연산 & 출력
    cout << "[Tree info]\n";
    cout << "Nodes : " << nodeCnt(1) << '\n';
    cout << "Leaf Nodes : " << leafCnt(1) << '\n';
    cout << "Height : " << treeHeight(1) << '\n';
}