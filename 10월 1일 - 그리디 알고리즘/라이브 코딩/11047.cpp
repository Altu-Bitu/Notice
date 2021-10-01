//
// Created by BaeSuA on 2021-10-01.
//

#include <iostream>
#include <vector>

using namespace std;

//필요한 동전 개수의 최솟값 구하는 함수
int coinCnt(int n, int k, vector<int> &coin) {
    int cnt = 0; //필요한 동전 개수 카운트
    for (int i = n - 1; i >= 0; i--) { //i:동전 인덱스, 큰 동전부터 사용 (그래야 동전 개수 최소가 됨)
        if (k == 0) //원하는 가치 합 만든 경우
            break;
        if (coin[i] <= k) { //동전 사용이 가능하면
            cnt += (k / coin[i]);
            k = k % coin[i]; //남은 가치값
        }
    }

    return cnt;
}

int main() {
    int n, k;

    //입력
    cin >> n >> k;
    vector<int> coin(n, 0);
    for (int i = 0; i < n; i++)
        cin >> coin[i];

    //연산 & 출력
    cout << coinCnt(n, k, coin);

    return 0;
}