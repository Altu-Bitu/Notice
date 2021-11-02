#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

//카드들의 점수 총합
ll sum(priority_queue<ll, vector<ll>, greater<>> &pq) {
    ll result = 0;
    while (!pq.empty()) {
        result += pq.top();
        pq.pop();
    }
    return result;
}

/**
 * 매번 숫자가 가장 작은 카드 2장을 뽑아야 최종 결과가 최솟값이 됨
 */
int main() {
    int n, m, input;
    priority_queue<ll, vector<ll>, greater<>> pq; //최소 힙

    //입력
    cin >> n >> m;
    while (n--) {
        cin >> input;
        pq.push(input);
    }

    //연산
    while (m--) {
        vector<ll> num(2);

        //카드의 총 수량은 변하지 않고, 카드의 개수 최솟값은 2이기 때문에 empty 체크를 하지 않아도 됨
        for (int i = 0; i < 2; i++) { //가장 숫자가 작은 카드 2장 뽑기
            num[i] = pq.top();
            pq.pop();
        }
        for (int i = 0; i < 2; i++) //계산 한 값을 덮어 쓰기
            pq.push(num[0] + num[1]);
    }

    //출력
    cout << sum(pq);
}