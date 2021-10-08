#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll greedyOil(vector<pair<ll, ll>> &city, int n) {
    ll cur_cost = city[0].second, tot_cost = 0;

    for (int i = 0; i < n; i++) {
        if (city[i].second < cur_cost) //이 도시의 기름값이 더 저렴하면 교체
            cur_cost = city[i].second;
        tot_cost += (cur_cost * city[i].first); //이동 비용
    }
    return tot_cost;
}

/**
 * 1. 길이가 무제한인 호스가 있다고 가정
 * 2. 지금까지 지나온 도시 중 가격이 가장 저렴한 주유소와 호스를 연결한다
 * 3. 이번에 도착한 도시의 기름값이 지금 호스에 연결된 주유소의 기름값보다 저렴하다면 호스 교체
 *
 * 상세 풀이 : https://myunji.tistory.com/224
 */
int main() {
    int n;

    //입력
    cin >> n;
    vector<pair<ll, ll>> city(n, {0, 0});
    for (int i = 0; i < n - 1; i++)
        cin >> city[i].first;
    for (int i = 0; i < n; i++)
        cin >> city[i].second;

    //연산 & 출력
    cout << greedyOil(city, n);
}