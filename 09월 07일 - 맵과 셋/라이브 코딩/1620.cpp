//
// Created by iw040 on 2021-09-07.
//

#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, m;
    string input;
    map<string, int> name; //이름이 입력되면 번호 출력
    map<int, string> number; //번호가 입력되면 이름을 출력

    //입력
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> input;
        name[input] = i; //key : 이름, value : 번호
        number[i] = input; //key : 번호, value : 이름
    }

    //출력
    while (m--) {
        cin >> input;
        if (isdigit(input[0])) //입력이 숫자라면
            cout << number[stoi(input)] << '\n'; //stoi : string to int
        else
            cout << name[input] << '\n';
    }
}