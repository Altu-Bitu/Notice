//
// Created by iw040 on 2021-09-07.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    string input;
    map<string, int> m;

    //입력
    cin >> n;
    for (int i = 0; i < n; i++) { //들어갈 때의 차들의 순서
        cin >> input;
        m[input] = i;
    }

    vector<int> seq;
    for (int i = 0; i < n; i++) {
        cin >> input;
        seq.push_back(m[input]);
    }

//    for(int i=0;i<n;i++)
//        cout<<seq[i]<<' ';

    int ans = 0; //추월한 차들의 수
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { //i번째로 나온 차보다 늦게 나온 모든 차들
            if (seq[i] > seq[j]) { //j번 차의 인덱스가 i번 차보다 작다면
                ans++;
                break;
            }
        }
    }
    cout << ans;
}