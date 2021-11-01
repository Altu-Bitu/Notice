#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

//str1과 str2가 서로 변환 가능한지 확인
bool convertible(string str1, string str2) {
    int diff = 0;
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] != str2[i])
            diff++;
    }
    return diff == 1;
}

//각 단어들 사이의 연결 관계 설정
map<string, vector<string>> makeGraph(vector<string> words, int size){
    map<string, vector<string>> graph;

    for (int i = 0; i < size; i++) {
        vector<string> list;
        for (int j = 0; j < size; j++) {
            if (convertible(words[i], words[j])) //서로 변환 가능한 단어라면 연결 관계 성립
                list.push_back(words[j]);
        }
        graph[words[i]] = list;
    }
    return graph;
}

//bfs로 begin에서 target으로 변환하는 가장 짧은 변환 과정 찾기
int bfs(map<string, vector<string>> graph, string begin, string target) {
    map<string, int> dist; //변환 단계 수
    queue<string> q;

    dist[begin] = 1; //초기값이 0이므로 1로 초기화
    q.push(begin);

    while (!q.empty()) {
        string cur = q.front();
        q.pop();

        if (cur == target) //target으로 변환 성공
            return dist[cur] - 1;

        vector<string> list = graph[cur];
        for (int i = 0; i < list.size(); i++) {
            string next_node = list[i]; //cur에서 변환 가능한 단어
            if (!dist[next_node]) { //아직 확인하지 않은 단어라면
                dist[next_node] = dist[cur] + 1;
                q.push(next_node);
            }
        }
    }
    return 0; //target으로 변환 실패
}

int solution(string begin, string target, vector<string> words) {
    words.push_back(begin); //시작 단어를 words 배열 안의 단어로 변환해야 하기 때문에 연결 관계 탐색에 넣어줌
    return bfs(makeGraph(words, words.size()), begin, target);
}

/**
 * begin에서 target으로 변환하는 가장 '짧은' 변환 과정
 * -> 최단거리 문제이므로 bfs
 *
 * 각 단어 사이 변환 가능 여부를 그래프의 연결 관계로 표현할 수 있음
 *
 * hit과 hot은 연결됨
 * hit과 cog는 연결되지 않음
 *
 * 연결 관계
 * hit | hot
 * hot | dot lot hit
 * dot | hot dog lot
 * dog | dot log cog
 * lot | hot dot log
 * log | dog lot cog
 * cog | dog log
 */
int main() {
    string begin = "hit";
    string target = "cog";
    vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};

    cout << solution(begin, target, words);
}