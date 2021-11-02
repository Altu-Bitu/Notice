#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

vector<bool> is_valid;

//최대 힙에서 top 데이터가 is_valid 할 때까지 pop
void deleteMax(priority_queue<ci> &heap) {
    while (!heap.empty() && !is_valid[heap.top().second])
        heap.pop();
}

//최소 힙에서 top 데이터가 is_valid 할 때까지 pop
void deleteMin(priority_queue<ci, vector<ci>, greater<>> &heap) {
    while (!heap.empty() && !is_valid[heap.top().second])
        heap.pop();
}

/**
 * 우선순위 큐 풀이
 * 최대 힙과 최소 힙을 동시에 관리하면서 각각의 힙에서 삭제된 데이터를 다른 힙에 반영하는 방법
 * -> 각 데이터의 유효성을 체크하는 배열을 만들기
 */
int main() {
    int t, k, n;
    char cmd;

    cin >> t;
    while (t--) {
        priority_queue<ci> max_heap; //최대 힙
        priority_queue<ci, vector<ci>, greater<>> min_heap; //최소 힙
        cin >> k;
        int idx = 0; //I 연산으로 입력된 숫자의 인덱스
        while (k--) {
            //입력
            cin >> cmd >> n;

            //연산
            switch (cmd) {
                case 'I': //두가지 힙 모두에 값을 넣은 뒤, is_valid 벡터에도 추가
                    max_heap.push(ci(n, idx));
                    min_heap.push(ci(n, idx));
                    is_valid.push_back(true);
                    idx++;
                    break;
                case 'D': //n에 따라 최대 힙 또는 최소 힙에서 데이터 삭제
                    if (n == 1) {
                        deleteMax(max_heap); //D연산 전처리
                        if (!max_heap.empty()) { //D연산
                            is_valid[max_heap.top().second] = false;
                            max_heap.pop();
                        }
                    }
                    if (n == -1) {
                        deleteMin(min_heap); //D연산 전처리
                        if (!min_heap.empty()) { //D연산
                            is_valid[min_heap.top().second] = false;
                            min_heap.pop();
                        }
                    }
                    break;
            }
        }
        //마지막으로 각 힙의 top이 valid 하도록 처리
        deleteMax(max_heap);
        deleteMin(min_heap);

        //출력
        if (max_heap.empty())
            cout << "EMPTY\n";
        else
            cout << max_heap.top().first << ' ' << min_heap.top().first << '\n';
        is_valid.clear(); //새로운 테스트 케이스 전 is_valid 벡터 초기화
    }
}