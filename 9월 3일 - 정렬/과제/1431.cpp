#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//문자열의 모든 자릿수 합을 구하는 함수
int sumNum(string str) {
    int sum = 0;
    for (int i = 0; i < str.size(); i++) {
        if (isdigit(str[i])) //문자(char)에 대해 숫자인지 판별하는 함수
            sum += str[i] - '0'; //char -> int로 바꾸는 방법 (아스키 코드에 대해 알아보세요)
    }
    return sum;
}

//비교함수
bool cmp(const string &s1, const string &s2) {
    if (s1.size() != s2.size()) //두 문자열의 길이가 다르다면 짧은 문자열이 먼저 오도록
        return s1.size() < s2.size();
    if (sumNum(s1) != sumNum(s2)) //두 문자열의 숫자 합이 다르다면 합이 작은 문자열이 먼저 오도록
        return sumNum(s1) < sumNum(s2);
    return s1 < s2; //사전순
}

int main() {
    int n;
    vector<string> serial_num;

    //입력
    cin >> n;
    serial_num.assign(n, "");
    for (int i = 0; i < n; i++)
        cin >> serial_num[i];

    //연산
    sort(serial_num.begin(), serial_num.end(), cmp);

    //출력
    for (int i = 0; i < n; i++)
        cout << serial_num[i] << '\n';
}