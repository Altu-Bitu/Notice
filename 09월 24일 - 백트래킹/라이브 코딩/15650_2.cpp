#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * permutation 이용한 조합 풀이 (0ms) (1759_2 주석 참고)
 *
 * 크기가 n인 배열에서 k개의 원소를 뽑는 방법
 *
 * n 크기의 배열을 준비하고 그 중 k개의 원소를 true로 셋팅
 * (ex) n=4, k=2일 때. arr = {1, 1, 0, 0}에 대한 prev_permutation 결과
 * {1, 1, 0, 0} -> {1, 0, 1, 0} -> {1, 0, 0, 1} -> {0, 1, 1, 0} -> {0, 1, 0, 1} -> {0, 0, 1, 1}
 * 1로 표시된 인덱스의 값만 연산에 포함하면 됨
 */

int main() {
    int n, m;

    //입력
    cin >> n >> m;
    vector<bool> num(n, false); //1 ~ n까지의 수에 대한 조합정보(true / false)

    //연산
    for (int i = 0; i < m; i++) //m개의 원소 true로 셋팅
        num[i] = true;

    do {
        for (int i = 0; i < n; i++) {
            if (num[i]) //true라면 사용이므로 출력
                cout << i + 1 << ' '; //인덱스는 0부터 시작이므로 +1로 출력
        }
        cout << '\n';
    } while (prev_permutation(num.begin(), num.end()));

    return 0;
}