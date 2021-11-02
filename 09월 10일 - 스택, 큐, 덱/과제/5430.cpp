#include <iostream>
#include <deque>
#include <string>

using namespace std;

deque<int> refactoring(string str) {
    deque<int> result;
    string tmp; //숫자를 담을 임시 문자열
    for (int i = 0; i < str.size(); i++) {
        if (isdigit(str[i])) //숫자라면 문자열에 추가
            tmp += str[i];
        else if (!tmp.empty() && (str[i] == ',' || str[i] == ']')) { //문자열이 비어있지 않을 때, 쉼표 또는 닫는 괄호를 만나면 숫자로 바꿔주기
            result.push_back(stoi(tmp));
            tmp = ""; //문자열 초기화
        }
    }
    return result;
}

string toStr(deque<int> dq, bool is_reversed) {
    if (dq.empty()) //덱이 비어있는 경우
        return "[]";

    string result = "[";
    while (!dq.empty()) {
        if (is_reversed) { //뒤집혔으면 뒤에서부터
            result += to_string(dq.back());
            dq.pop_back();
        } else { //올바른 순서면 앞에서부터
            result += to_string(dq.front());
            dq.pop_front();
        }
        result += ",";
    }
    result[result.size() - 1] = ']'; //마지막 쉼표를 닫는 괄호로 바꿔주기
    return result;
}

/**
 * 함수 R에서 실제로 배열을 뒤집을 필요가 없다는게 핵심
 * 비어있는 배열을 리턴하는 경우를 주의
 */
int main() {
    int t, n;
    string p, str;

    cin >> t;
    while (t--) {
        //입력
        bool is_reversed = false, is_error = false;
        cin >> p >> n >> str;

        //연산
        deque<int> dq = refactoring(str); //문자열에서 숫자를 구해서 덱에 넣기
        for (int i = 0; i < p.size(); i++) {
            if (p[i] == 'R') { //함수 R : is_reversed 변수만 반대로 바꿔주기
                is_reversed = !is_reversed;
                continue;
            }
            //함수 D
            if (dq.empty()) { //배열이 비어있으면 error
                is_error = true;
                break;
            }
            if (is_reversed) //뒤집힌 배열이면 맨 뒤 데이터 삭제
                dq.pop_back();
            else //올바른 순서의 배열이면 맨 앞 데이터 삭제
                dq.pop_front();
        }

        //출력
        if (is_error)
            cout << "error\n";
        else //숫자를 다시 문자열에 담아서 리턴하기
            cout << toStr(dq, is_reversed) << '\n';
    }
}