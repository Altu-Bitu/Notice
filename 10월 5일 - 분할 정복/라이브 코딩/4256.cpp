//
// Created by iw040 on 2021-10-05.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> preorder, inorder_idx;

//트리를 분할하여 postorder 결과를 출력하는 함수
void divide(int idx, int left, int right) {
    if (left > right) //기저조건 : 왼쪽 경계가 오른쪽 경계 너머에 있음
        return;
    int root = preorder[idx]; //root의 값
    int root_idx = inorder_idx[root]; //inorder에서의 root 위치

    divide(idx + 1, left, root_idx - 1); //왼쪽 서브 트리
    divide(idx + (root_idx - left) + 1, root_idx + 1, right); //오른쪽 서브 트리
    cout << root << ' '; //출력
}


int main() {
    int t, n, num;

    cin >> t;
    while (t--) {
        //입력
        cin >> n;
        preorder.assign(n, 0);
        inorder_idx.assign(n + 1, 0);

        for (int i = 0; i < n; i++) //preorder는 그대로 입력
            cin >> preorder[i];
        for (int i = 0; i < n; i++) { //inorder는 노드의 위치 입력
            cin >> num;
            inorder_idx[num] = i;
        }

        //연산
        divide(0, 0, n - 1);
        cout << '\n';
    }
}