#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

vector<bool> visited;

ci findGiga(int node, vector<vector<ci>> &tree) {
    /**
     * 기둥만 있는 경우
     * 이 문제의 테스트 케이스는 정점이 1~n 순서로 입력되기 때문에
     * 리프 노드가 n번 정점이란 것이 보장되지만, 모든 문제에서 성립하지 않음
     */
    int giga_pos = tree.size() - 1;
    int trunk_len = 0; //기둥의 길이

    //루트 노드가 기가 노드인 경우
    if (tree[node].empty() || tree[node].size() == 2)
        return {node, 0};
    do {
        if (tree[node].size() > 2) { //기가 노드
            giga_pos = node;
            break;
        }
        visited[node] = true; //기둥 방문 처리
        int next = (visited[tree[node][0].first]) ? 1 : 0; //자식 노드
        trunk_len += tree[node][next].second;
        node = tree[node][next].first;
    } while (tree[node].size() != 1); //루트거나, 리프거나
    return {giga_pos, trunk_len};
}

int branchLen(int node, vector<vector<ci>> &tree) {
    visited[node] = true; //가지 방문 처리
    int len = 0;
    for (int i = 0; i < tree[node].size(); i++) {
        int next_node = tree[node][i].first;
        if (visited[next_node])
            continue;
        //가장 긴 가지로 갱신
        len = max(len, tree[node][i].second + branchLen(next_node, tree));
    }
    return len;
}

/**
 * 필요한 연산
 * 1. 기가 노드 위치 찾으면서 기둥의 높이 구하기
 * 2. 가장 긴 가지의 길이 구하기
 *
 * !주의! 입력이 부모-자식 관계로 주어지는 것이 아니라 무방향 그래프로 주어짐
 * (루트가 주어지므로 무방향 그래프를 입력받고 트리로 만든 뒤 연산해도 되지만 이 코드에선 그렇게 하지 않음)
 *
 * 기가 노드 찾기
 * 1. 루트와 리프 노드가 아니라면 모든 노드는 2개 이상의 노드와 연결됨 (부모 + 자식)
 * 2. 만약 기가 노드라면, 3개 이상의 노드와 연결됨 (부모 1 + 자식 2 이상)
 *    2-1. 루트가 기가 노드라면, 2개 이상의 노드와 연결됨 (자식 2 이상)
 * 3. 리프 노드에 다다를 때까지 기가 노드를 찾지 못한다면 리프 노드가 기가 노드
 *
 * 가장 긴 가지의 길이 찾기
 * 1. PPT 트리의 높이를 구하는 연산 응용
 * 2. 모든 자식 노드에 대해 재귀 함수를 호출해 max 함수로 가장 긴 가지 찾기
 */
int main() {
    int n, r, a, b, d;

    //입력
    cin >> n >> r;
    vector<vector<ci>> tree(n + 1, vector<ci>(0));
    visited.assign(n + 1, false);
    while (--n) { //무방향 그래프
        cin >> a >> b >> d;
        tree[a].emplace_back(b, d);
        tree[b].emplace_back(a, d);
    }

    //연산
    ci giga = findGiga(r, tree);

    //연산 & 출력
    cout << giga.second << ' ' << branchLen(giga.first, tree);
}