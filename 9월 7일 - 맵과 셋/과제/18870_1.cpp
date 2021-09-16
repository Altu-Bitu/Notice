#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * BST와 같은 원리
 * lower_bound 함수 사용 가능 (예습)
 */
int binarySearch(int left, int right, int target, vector<int> &sorted) {
    while (left <= right) { //left, right 위치가 반전되면 break
        int mid = (left + right) / 2; //중앙값
        if (target == sorted[mid]) //target의 인덱스를 찾음
            return mid;
        if (target > sorted[mid]) //target이 오른쪽에 있음
            left = mid + 1;
        else if (target < sorted[mid]) //target이 왼쪽에 있음
            right = mid - 1;
    }
    return -1; //target을 찾지 못함
}

/**
 * 예제 입력 1을 중복없이 오름차순 정렬
 * -10 -9 2 4
 *
 * 숫자 k가 있을 때 k의 좌표 압축 결과는 위 배열에서 k값의 인덱스
 * ex) k = -10 -> 좌표 압축 결과 = 0
 */
int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<int> arr, sorted;
    set<int> s;

    //입력
    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]); //입력을 셋에 넣으며 중복 제거 + 오름차순 정렬
    }

    //랜덤 인덱스 엑세스를 위해 set을 vector에 옮기기
    for (auto iter = s.begin(); iter != s.end(); iter++)
        sorted.push_back(*iter);

    //출력
    //sorted 배열에서의 arr[i] 값의 인덱스 찾기
    for (int i = 0; i < n; i++)
        cout << binarySearch(0, sorted.size() - 1, arr[i], sorted) << ' ';
}