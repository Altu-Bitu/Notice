#include <iostream>
#include <map>

using namespace std;

int main() {
    double cnt = 0; //입력된 나무의 전체 개수
    string input;
    map<string, double> m;

    //입력
    /*
     * getline : 띄어쓰기까지 포함해서 입력을 받는 함수
     * EOF : 입력이 들어오지 않을 때까지 받기. while문 안에 cin 하기
     */
    while (getline(cin, input)) {
        m[input]++; //특정 나무의 수
        cnt++;
    }

    //출력
    //소수점 고정하는 방법 확인
    cout << fixed;
    cout.precision(4);
    for (auto iter = m.begin(); iter != m.end(); iter++)
        cout << iter->first << ' ' << (iter->second * 100.0) / cnt << '\n';
}