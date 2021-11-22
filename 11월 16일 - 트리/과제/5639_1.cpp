#include <iostream>
#include <vector>

using namespace std;

void postorder(int left, int right, vector<int> &nodes) {
    if (left > right) //기저조건 : 왼쪽 경계가 오른쪽 경계 너머에 있음
        return;

    //처음으로 root 노드보다 값이 커지는 위치
    int idx = right + 1;
    for (int i = left; i <= right; i++) {
        if (nodes[i] > nodes[left]) {
            idx = i;
            break;
        }
    }

    postorder(left + 1, idx - 1, nodes); //왼쪽 서브트리
    postorder(idx, right, nodes); //오른쪽 서브트리
    cout << nodes[left] << '\n'; //출력
}

/**
 * 분할 정복 - 4256번 참고
 *
 * 분할 정복 풀이
 * 1. 전위 순회는 root 노드의 위치는 알 수 있지만 왼쪽, 오른쪽 서브트리의 경계는 알 수 없음
 * 2. BST의 성질 : 왼쪽 서브트리의 모든 노드 값 < 루트 노드 값 < 오른쪽 서브트리의 모든 노드 값
 *    -> 처음으로 root 보다 값이 커진다면, 그 위치가 왼쪽, 오른쪽 서브트리의 경계
 * 3. 재귀함수 호출로 분할 반복하며 출력
 */
int main() {
    int input;
    vector<int> nodes;

    //입력
    while (cin >> input)
        nodes.push_back(input);

    //연산
    postorder(0, nodes.size() - 1, nodes);
}