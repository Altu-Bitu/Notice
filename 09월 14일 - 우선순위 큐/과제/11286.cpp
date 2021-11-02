#include <iostream>
#include <queue>

using namespace std;

/**
 * 우선순위 큐의 비교함수
 * sort 함수의 비교함수 형식과 비교해보기
 */
struct cmp {
    bool operator()(int a, int b) {
        if (abs(a) == abs(b))
            return a > b;
        return abs(a) > abs(b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, cmp> pq;
    int n, x;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 0) {
            if (pq.empty()) //런타임 에러 방지
                cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else
            pq.push(x);
    }
}