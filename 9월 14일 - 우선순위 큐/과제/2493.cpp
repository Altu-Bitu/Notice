#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * [문제설명]
 * 탑은 모두 왼쪽 방향으로 레이저를 보냄
 * 각 탑에서 발사한 레이저 신호를 어느 탑에서 수신하는지 알아내는 문제
 *
 * [문제풀이]
 * 스택에 탑의 높이가 아닌 인덱스를 넣어야 함을 파악해 푸는 문제
 * 항상 스택의 top에 있는 인덱스의 탑 높이가 낮아야 함 (자신보다 높은 탑 중 가장 왼쪽에 있는 탑이 신호 수신하기 때문)
 * 1. (1 ~ n) 따라서 스택의 top에 있는 인덱스의 탑 높이가 현재 탑 높이와 같거나 낮다면 pop
 * 1. (1 ~ n) 앞의 과정이 끝난 후 스택이 비어있지 않다면 top에 있는 인덱스가 현재 탑의 신호를 수신하는 탑임
 * 2. (n ~ 1) 따라서 스택의 top에 있는 인덱스의 탑 높이가 현재 탑 높이보다 낮다면 현재 탑이 수신탑
 */

//1 ~ n 돌면서 수신탑 찾기
vector<int> transTop1(int n, vector<int> &num) {
    stack<int> st;
    vector<int> ans(n + 1, 0); //수신 탑 저장

    for (int i = 1; i <= n; i++) {
        while (!st.empty() && num[st.top()] <= num[i]) { //현재 탑 높이보다 st.top() 인덱스의 탑 높이가 같거나 낮다면 pop
            st.pop();
        }
        if (!st.empty()) ans[i] = st.top(); //스택이 비어있지 않다면 스택의 top에 저장된 인덱스가 현재 탑의 신호 수신탑
        st.push(i); //현재 탑 인덱스 스택에 push
    }

    return ans;
}

//n ~ 1 돌면서 수신탑 찾기
vector<int> transTop2(int n, vector<int> &num) {
    stack<int> st;
    vector<int> ans(n + 1, 0); //수신 탑 저장

    for (int i = n; i >= 1; i--) {
        while (!st.empty() && num[st.top()] < num[i]) { //현재 탑 높이보다 st.top() 인덱스의 탑 높이가 낮다면 현재 탑이 수신탑
            ans[st.top()] = i;
            st.pop(); //수신탑이 정해졌으므로 pop
        }
        st.push(i); //현재 탑 인덱스 스택에 push
    }

    return ans;
}

int main() {
    int n;

    //입력
    cin >> n;

    vector<int> num(n + 1, 0); //탑의 인덱스가 1부터 시작하므로 n+1 할당
    for (int i = 1; i <= n; i++)
        cin >> num[i];

    //연산
    //vector<int> ans = transTop1(n, num);
    vector<int> ans = transTop2(n, num);

    //출력
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}