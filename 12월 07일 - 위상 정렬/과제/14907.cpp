#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 26;

vector<string> splitInput(string input) { //입력 문자열 분리
    vector<string> result; //작업 번호, 작업 일수, 전에 해야하는 작업 목록 순서로 저장
    string tmp;
    input += " "; //마지막 문자열 분리를 위해 공백 추가
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            result.push_back(tmp);
            tmp = "";
            continue;
        }
        tmp += input[i];
    }
    return result;
}

//위상정렬 + DP
int topologicalSort(vector<int> &days, vector<int> &indegree, vector<vector<int>> &graph) {
    queue<int> q;
    vector<int> dp(SIZE, 0); //현재 작업 하기까지 걸린 시간
    int ans = 0;

    for (int i = 0; i < SIZE; i++) {
        dp[i] = days[i]; //dp 배열 초기화
        if (days[i] && !indegree[i]) //존재하는 정점이고, 진입차수가 0이라면
            q.push(i);
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        ans = max(ans, dp[node]); //정답 갱신 (마지막 정점이 여러 개일 경우, 가장 긴 시간을 선택해야 하기 때문)
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i];
            indegree[next_node]--; //연결된 정점의 진입차수를 1씩 감소
            if (!indegree[next_node]) //연결된 정점의 진입차수가 0이 되었다면
                q.push(next_node);

            //다음 정점의 최소 시간 계산 -> 이어진 전 정점 중 가장 긴 작업 일수를 가진 정점을 선택
            dp[next_node] = max(dp[next_node], dp[node] + days[next_node]);
        }
    }
    return ans;
}

/**
 * 입력은 EOF를 통해 받아야 함 (입력이 없을 때까지)
 * 위상 정렬의 끝나는 정점이 여러 개일 경우, 가장 긴 시간을 선택해야 하기 때문에 정답을 항상 max처리 해주어야 함
 *
 * !주의! 입력으로 들어오는 그 전에 해야 할 작업은 0개일 수 있음. 즉 주어지지 않을 수 있음.
 * -> 따라서, getline을 통해 한 번에 입력받은 후, 작업, 작업 일수, 이 전에 해야 할 작업으로 나눠서 저장
 */

int main() {
    vector<int> indegree(SIZE, 0);
    vector<vector<int>> graph(SIZE, vector<int>(0));
    vector<int> days(SIZE, 0);
    string input;

    //입력
    while (getline(cin, input)) {
        vector<string> list = splitInput(input);
        int work = list[0][0] - 'A'; //작업 번호
        days[work] = stoi(list[1]); //해당 작업 일수
        if (list.size() == 2) //그 전에 해야 하는 작업이 없다면
            continue;

        string prev = list[2]; //그 전에 해야 하는 작업
        indegree[work] = prev.length();
        for (int i = 0; i < prev.length(); i++)
            graph[prev[i] - 'A'].push_back(work);
    }

    //연산 & 출력
    cout << topologicalSort(days, indegree, graph);
}