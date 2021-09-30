#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 10;

int k;
bool is_find;
vector<char> op(SIZE); //부등호
vector<int> arr(SIZE), num(SIZE);
vector<bool> check(SIZE);

//수열을 문자열로 바꾸는 함수
string arrToString(vector<int> &arr) {
    string result;
    for (int i = 0; i <= k; i++)
        result += (arr[i] + '0');
    return result;
}

//과정에서의 답이 가능성 있는 답인지 체크하는 함수
bool promising(int idx) {
    if (op[idx] == '<' && arr[idx] > arr[idx + 1]) //부등호가 '<'인데 '>'관계일 때
        return false;
    if (op[idx] == '>' && arr[idx] < arr[idx + 1]) //부등호가 '>'인데 '<'관계일 때
        return false;
    return true;
}

//최댓값 or 최솟값 구하는 백트래킹 함수 (num배열을 통해 구분)
void findValue(int cnt) {
    //수가 2개 이상이 배치됐다면, 주어진 부등호 만족하는지 검사, 만족하지 않으면 바로 리턴 (가지치기)
    if (cnt >= 2 && !promising(cnt - 2))
        return;
    if (cnt == k + 1) { //부등호 만족하는 수를 찾음 (기저조건)
        is_find = true;
        return;
    }
    for (int i = 0; i <= k; i++) { //num[i]: 최댓값이면 9 ~ (9-k), 최솟값이면 0 ~ k
        if (!check[num[i]]) {
            check[num[i]] = true;
            arr[cnt] = num[i];
            findValue(cnt + 1);
            if (is_find)
                return;
            check[num[i]] = false;
            arr[cnt] = 0;
        }
    }
}

/**
 * [백트래킹 풀이] (0ms)
 * 수를 중복없이 배치함 (N과 M(1)과 동일)
 * 수를 배치할 때마다 해당 수가 그 전 수와 부등호 관계를 만족하는지 확인, 만족하지 않으면 back (가지치기)
 */

int main() {
    string max_num, min_num; //정답

    //입력
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> op[i];
    }

    //최댓값 연산
    for (int i = 0; i <= k; i++) //num배열에 값 미리 저장
        num[i] = 9 - i; //최댓값은 9부터 (9-k)까지 숫자로 이루어짐
    findValue(0);
    max_num = arrToString(arr);

    //초기화 !주의! 전역변수 사용 시 초기화 빼먹기 쉬우니 잘 체크하자
    is_find = false;
    check.assign(SIZE, false);
    arr.assign(SIZE, 0);

    //최솟값 연산
    for (int i = 0; i <= k; i++)
        num[i] = i; //최솟값은 0부터 k까지 숫자로 이루어짐
    findValue(0);
    min_num = arrToString(arr);

    //출력
    cout << max_num << '\n' << min_num;

    return 0;
}