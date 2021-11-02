#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

/**
 * [영단어 우선순위]
 * 1. 자주 나오는 단어일수록 앞에 배치
 * 2. 해당 단어의 길이가 길수록 앞에 배치
 * 3. 알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치
 */

map<string, int> word_cnt;

bool cmp(const string &a, const string &b) {
    if (word_cnt[a] != word_cnt[b]) //자주 나오는 단어일수록 앞에 배치
        return word_cnt[a] > word_cnt[b];
    if (a.length() != b.length()) //해당 단어의 길이가 길수록 앞에 배치
        return a.length() > b.length();
    return a < b; //알파벳 사전 순서로 배치
}

int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> words;
    string word;
    int n, m;

    //입력
    cin >> n >> m;

    //입력 + 영단어 횟수 저장
    while (n--) {
        cin >> word;
        if (word.length() < m) //길이가 m 미만이면 영단어장에 들어가지 않음
            continue;
        if (!word_cnt[word]) //중복 영단어 들어가는 것 방지
            words.push_back(word);
        word_cnt[word]++; //word 단어 횟수 증가
    }

    //조건에 맞게 정렬
    sort(words.begin(), words.end(), cmp);

    //출력
    for (int i = 0; i < words.size(); i++)
        cout << words[i] << '\n';

    return 0;
}