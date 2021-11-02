#include <iostream>
#include <vector>
#include <utility> //vector 헤더에 포함됐기 때문에 생략해도 무관
#include <algorithm>

using namespace std;

//비교 함수
bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) {
    if (p1.second != p2.second) //y 좌표가 다르면 y 좌표가 증가하는 순서로
        return p1.second < p2.second;
    return p1.first < p2.first; //x 좌표가 증가하는 순서로
}

int main() {
    int n;
    vector<pair<int, int>> arr;

    //입력
    cin >> n;
    arr.assign(n, make_pair(0, 0));
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;

    //연산
    sort(arr.begin(), arr.end(), cmp);

    //출력
    for (int i = 0; i < n; i++)
        cout << arr[i].first << ' ' << arr[i].second << '\n';
}