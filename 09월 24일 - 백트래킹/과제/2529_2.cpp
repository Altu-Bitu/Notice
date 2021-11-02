#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> op;

//수열을 문자열로 바꾸는 함수
string arrToString(vector<int> &arr) {
    string result;
    for (int item:arr)
        result += (item + '0');
    return result;
}

//입력받은 수열이 부등호 관계를 만족하는지 확인하는 함수
bool promising(vector<int> &arr) {
    int before = arr[0];
    for (int i = 0; i < op.size(); i++) {
        if ((op[i] == '<') && (before > arr[i + 1])) //부등호가 '<'인데 '>' 관계일 때
            return false;
        if ((op[i] == '>') && (before < arr[i + 1])) //부등호가 '>'인데 '<' 관계일 때
            return false;
        before = arr[i + 1];
    }
    return true;
}

//가능한 최대 정수 수열 찾아서 문자열로 리턴하는 함수
string findMax(vector<int> &arr) {
    /**
     * arr = {9, 8, 7}일 때
     * {9, 8, 7} -> {9, 7, 8} -> {8, 9, 7} -> {8, 7, 9} -> {7, 9, 8} -> {7, 8, 9}
     */
    do {
        if (promising(arr))
            return arrToString(arr);
    } while (prev_permutation(arr.begin(), arr.end()));
}

//가능한 최소 정수 수열 찾아서 문자열로 리턴하는 함수
string findMin(vector<int> &arr) {
    /**
     * arr = {7, 8, 9}일 때
     * {7, 8, 9} -> {7, 9, 8} -> {8, 7, 9} -> {8, 9, 7} -> {9, 7, 8} -> {9, 8, 7}
     */
    do {
        if (promising(arr))
            return arrToString(arr);
    } while (next_permutation(arr.begin(), arr.end()));
}

/**
 * permutation 이용한 순열 풀이 (16ms)
 * next_permutation : 현재의 수열에서 사전 순서상 다음 순열이 있다면, true를 반환하고 해당 수열을 다음 순열로 변경
 * prev_permutation : 현재의 수열에서 사전 순서상 이전 순열이 있다면, true를 반환하고 해당 수열을 이전 순열로 변경
 *
 * arr = {1, 2, 3, 4}일 때
 * arr -> next_permutation -> true, arr = {1, 2, 4, 3}
 * arr -> prev_permutation -> false
 *
 * arr = {4, 3, 2, 1}일 때
 * arr -> next_permutation -> false
 * arr -> prev_permutation -> true, arr = {4, 3, 1, 2}
 *
 * !생각해보기! 왜 while문이 아니라 do-while문을 사용할까요?
 */
int main() {
    int k;
    string max_num, min_num;
    vector<int> arr;

    //입력
    cin >> k;
    op.assign(k, ' ');
    arr.assign(k + 1, 0);
    for (int i = 0; i < k; i++)
        cin >> op[i];

    //연산

    //최대 정수
    //가장 큰 수인 9부터 k개의 숫자가 최대 정수를 이루는 숫자임
    for (int i = 0; i <= k; i++)
        arr[i] = 9 - i;
    max_num = findMax(arr);

    //최소 정수
    //가장 작은 수인 0부터 k개의 숫자가 최소 정수를 이루는 숫자임
    for (int i = 0; i <= k; i++)
        arr[i] = i;
    min_num = findMin(arr);

    //출력
    cout << max_num << '\n' << min_num;
}
