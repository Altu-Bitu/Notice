#include <iostream>
#include <vector>

using namespace std;

vector<bool> truth; //진실을 아는지 여부
vector<int> parent;

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) //루트 정점
        return node;
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
        return;
    if (truth[xp] || truth[yp]) //둘 중 하나라도 진실을 믿는 사람이 있다면 표시
        truth[xp] = truth[yp] = true;
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp];
        parent[yp] = xp;
    } else { //새로운 루트 yp
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
}

int liarParty(vector<int> &parties) {
    int cnt = 0;
    for (int i = 0; i < parties.size(); i++) {
        int root = findParent(parties[i]); //파티 집합의 루트 정점
        if (!truth[root])
            cnt++;
    }
    return cnt;
}

/**
 * 1. 각 사람들은 다양한 파티를 통해 연결됐다고 할 수 있음
 * 2. 연결된 사람들은 같은 집합에 속함
 * 3. 각 집합에 속한 사람들 중 한 명이라도 진실을 안다면 그 집합의 사람들이 속한 파티에는 거짓말을 할 수 없음
 * -> 유니온 파인드로 사람들을 집합으로 묶은 뒤, 파티마다 거짓말을 할 수 있는지 확인하기
 *
 * !주의! 파티 정보를 입력받으며 바로 거짓말 가능 여부를 판단할 수 없음 (예제 입력 4)
 *       각 파티에서 한 사람만 저장해둔 뒤, 마지막에 거짓말 가능 여부 한 번에 판단
 */
int main() {
    int n, m;

    //입력
    cin >> n >> m;
    truth.assign(n + 1, false);
    parent.assign(n + 1, -1);

    int init, p;
    cin >> init;
    while (init--) { //진실을 아는 사람들
        cin >> p;
        truth[p] = true;
    }

    int cnt, first_person, people;
    vector<int> parties;
    while (m--) {
        cin >> cnt >> first_person;

        //연산
        parties.push_back(first_person); //파티 정보로 각 파티의 첫번째 사람만 저장
        while (--cnt) {
            cin >> people;
            unionInput(first_person, people);
        }
    }

    int ans = liarParty(parties);

    //출력
    cout << ans;
}