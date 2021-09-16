//
// Created by iw040 on 2021-09-10.
//

#include <iostream>
#include <stack>
#include <map>

using namespace std;

//괄호의 짝을 저장할 맵
map<char, char> bracket;

//괄호가 균형을 이루었는지 확인하는 함수
bool isBalanced(string input) {
    stack<char> s;

    for (int i = 0; i < input.size(); i++) {
        switch (input[i]) {
            case '(': case '[': //왼쪽 괄호
                s.push(input[i]);
                break;
            case ')': case ']': //오른쪽 괄호
                if (s.empty() || s.top() != bracket[input[i]])
                    return false;
                s.pop();
                break;
        }
//        if (input[i] == '(' || input[i] == '[')
//            s.push(input[i]);
//        else if (input[i] == ')') {
//            if (s.empty() || s.top() != '(')
//                return false;
//            s.pop();
//        } else if (input[i] == ']') {
//            if (s.empty() || s.top() != '[')
//                return false;
//            s.pop();
//        }
    }
    //return true; //'()(' 반례
    return s.empty();
}

int main() {
    string input;
    bracket[')'] = '(';
    bracket[']'] = '[';

    while (true) {
        //입력
        getline(cin, input); //띄어쓰기 포함 입력 받기
        if (input == ".")
            break;

        //연산 & 출력
        //input에 대해 괄호 맞는지 확인
        if (isBalanced(input))
            cout << "yes\n";
        else
            cout << "no\n";
        //삼항 연산자
        //cout << ((isBalanced(input)) ? "yes" : "no") << '\n';
    }
}