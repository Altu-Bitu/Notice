//
// Created by iw040 on 2021-09-03.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//정렬할 배열, 정렬한 배열
vector<int> arr, sorted;

//start ~ end 사이의 원소를 출력하는 함수
void printArr(int start, int end, string tag) {
    cout << tag << " array : ";
    for (int i = start; i <= end; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

//합병 정렬(conquer, merge)
void merge(int left, int mid, int right) {
    int p1 = left, p2 = mid + 1, p3 = left;

    while (p1 <= mid && p2 <= right) {
        if (arr[p1] <= arr[p2]) //왼쪽 배열의 값이 오른쪽 배열의 값보다 작거나 같다
            sorted[p3++] = arr[p1++];
        else //왼쪽 배열의 값이 오른쪽 배열의 값보다 큼
            sorted[p3++] = arr[p2++];
    }
    while (p1 <= mid) //왼쪽 배열에 탐색하지 않은 원소가 있나?
        sorted[p3++] = arr[p1++];
    while (p2 <= right) //오른쪽 배열에 탐색하지 않은 원소가 있나?
        sorted[p3++] = arr[p2++];
    for (int i = left; i <= right; i++) //복사
        arr[i] = sorted[i];
}

//합병 정렬(divide)
void mergeSort(int left, int right) {
    if (left < right) { //더 나눌 수 있다면
        int mid = (left + right) / 2; //정확히 둘로 나눈다
        mergeSort(left, mid); //왼쪽 배열
        mergeSort(mid + 1, right); //오른쪽 배열

        //정렬 전 배열 출력
        printArr(left, mid, "Left");
        printArr(mid + 1, right, "Right");

        merge(left, mid, right); //합치기

        //정렬 후 배열 출력
        printArr(left, right, "Merged");
        cout << '\n';
    }
}

int main() {
    int n;

    //입력
    cin >> n;
    arr.assign(n, 0);
    sorted.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //연산
    //mergeSort(0, n - 1);
    sort(arr.begin(), arr.end());

    //출력
    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';
}