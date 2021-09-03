//
// Created by iw040 on 2021-09-03.
//

#include <iostream>
#include <vector>

using namespace std;

//정렬할 배열
vector<int> arr;

//버블 정렬
//n = 5 -> 4+3+2+1 = 10
void bubbleSort(int n) {
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        //0 ~ n-1까지 정렬 -> 0 ~ n-2까지 정렬 -> ... -> 0 ~ 1까지 정렬
        for (int j = 1; j < n - i; j++) {
            if (arr[j - 1] > arr[j]) {
                //swap
//                int tmp = arr[j - 1];
//                arr[j - 1] = arr[j];
//                arr[j] = tmp;
                swap(arr[j - 1], arr[j]);
            }
            cnt++;
        }
    }
    cout << "Count : " << cnt << '\n';
}

//향상된 버블 정렬
void bubbleSortAdv(int n){
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        bool flag = true;
        //0 ~ n-1까지 정렬 -> 0 ~ n-2까지 정렬 -> ... -> 0 ~ 1까지 정렬
        for (int j = 1; j < n - i; j++) {
            if (arr[j - 1] > arr[j]) {
                flag = false;
                swap(arr[j - 1], arr[j]);
            }
            cnt++;
        }
        //출력할게 아니라면 return 으로 수정해도 됨
        if(flag)
            break;
    }
    cout << "Count : " << cnt << '\n';
}

int main() {
    int n;

    //입력
    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //연산
    //bubbleSort(n);
    bubbleSortAdv(n);

    //출력
    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';
}