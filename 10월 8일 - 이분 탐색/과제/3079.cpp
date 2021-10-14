#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> immigration;

//심사를 받는데 걸리는 시간이 tot_time일 때, 심사를 받을 수 있는 사람의 수
ll cntPeople(ll tot_time) {
    ll cnt = 0;
    for (int i = 0; i < immigration.size(); i++)
        cnt += (tot_time / immigration[i]);
    return cnt;
}

ll lowerSearch(ll left, ll right, int target) {
    ll ans = 0;
    while (left <= right) {
        //심사를 받는데 걸리는 시간이 mid일 때, 몇 명의 친구들이 심사를 받을 수 있는가?
        ll mid = (left + right) / 2;
        ll entrance = cntPeople(mid);

        if (entrance >= target) {
            ans = mid;
            right = mid - 1;
        } else if (entrance < target)
            left = mid + 1;
    }
    return ans;
}

/**
 * 상근이와 친구들이 심사를 받는데 걸리는 시간의 최솟값
 * -> 시간이 t만큼 주어질 때, m명 이상의 친구들이 입국 심사를 받을 수 있는가?
 *
 * left : 모든 심사대의 심사 시간이 k이고, 심사대가 친구들의 수만큼 주어진다면 걸리는 시간은 k
 * right : 심사가 가장 오래 걸리는 심사대 k에서 모든 친구들이 한명씩 입국심사를 받는다면, 걸리는 시간은 k*m
 *
 * !주의! right k*m의 최댓값은 심사 시간의 최댓값 10^9와 m의 최댓값 10^9를 곱한 10^18이다.
 * 그러므로 long long 범위를 써야 함.
 */
int main() {
    int n, m;
    ll max_time = 0, min_time = 1e9;

    //입력
    cin >> n >> m;
    immigration.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> immigration[i];
        max_time = max(max_time, immigration[i]);
        min_time = min(min_time, immigration[i]);
    }

    //연산 & 출력
    cout << lowerSearch(min_time, max_time * m, m);
}