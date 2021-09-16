#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 인덱스와 함께 예제 입력 1을 오름차순 정렬
 * (-10, 2) (-9, 4) (2, 0) (4, 1) (4, 3)
 *
 * 정렬 후 i번째 좌표에 대해 :
 * i-1번째 좌표와 값이 같음 -> 좌표 압축 결과도 같음 (ex) i = 4
 * i-1번째 좌표와 값이 다름 -> 좌표 압축 결과는 (i-1번째 좌표의 좌표 압축 결과) + 1 (ex) i = 1
 *
 * i = 0일 때의 경우를 연산하지 않는 이유 : 계산할 필요 없이 0이기 때문 (초기값)
 */
int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<pair<int, int>> arr;
    vector<int> result;

    //입력
    cin >> n;
    arr.assign(n, make_pair(0, 0));
    result.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first; //좌표
        arr[i].second = i; //좌표의 원래 인덱스
    }

    //연산
    sort(arr.begin(), arr.end()); //정렬
    for (int i = 1; i < n; i++) {
        if (arr[i - 1].first == arr[i].first) //이전의 좌표와 같은 좌표라면 좌표 압축 결과도 같음
            result[arr[i].second] = result[arr[i - 1].second];
        else //이전의 좌표와 다른 좌표라면 좌표 압축 결과는 이전의 좌표보다 1이 큼
            result[arr[i].second] = result[arr[i - 1].second] + 1;
    }

    //출력
    for (int i = 0; i < n; i++)
        cout << result[i] << ' ';
}