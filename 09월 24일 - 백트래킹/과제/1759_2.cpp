#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_vowel[26];

//가능성 있는 암호인지 체크하는 함수
bool promising(int l, vector<char> &alpha, vector<bool> &comb) {
    int vowel_cnt = 0, size = comb.size();
    for (int i = 0; i < size; i++) {
        if (!comb[i]) //연산에 포함되지 않는 문자
            continue;
        if (is_vowel[alpha[i]-'a']) //모음이라면
            vowel_cnt++;
    }
    return (vowel_cnt >= 1) && ((l - vowel_cnt) >= 2);
}

//문자 배열을 문자열로 만드는 함수
string charToString(vector<char> &alpha, vector<bool> &comb) {
    string result;
    for (int i = 0; i < comb.size(); i++) {
        if (comb[i]) //연산에 포함된 문자라면 result에 더하기
            result += alpha[i];
    }
    return result;
}

/**
 * permutation 이용한 조합 풀이 (2529_2.cpp, 15661_2.cpp 주석을 먼저 봐주세요)
 *
 * 크기가 n인 배열에서 k개의 원소를 뽑는 방법
 *
 * 1. 비트마스킹 -> 00...00~11...11까지 확인 but 비트마다 k개가 뽑힌게 맞는지 추가 연산 필요.
 *    (ex) n=4, k=2일 때. 조건에 맞는건 {0011, 0101, 1001, 1010, 1100, 0110}이지만 {1111, 1110}등도 반복문에 들어옴
 *         비트마스킹은 (n^2)개의 경우의 수를 고려하지만, 여기선 (nCk)개의 경우만 필요하기 때문에 시간낭비
 *
 * 2. permutation -> n 크기의 배열을 준비하고 그 중 k개의 원소를 true로 셋팅
 *    (ex) n=4, k=2일 때. arr = {1, 1, 0, 0}에 대한 prev_permutation 결과
 *         {1, 1, 0, 0} -> {1, 0, 1, 0} -> {1, 0, 0, 1} -> {0, 1, 1, 0} -> {0, 1, 0, 1} -> {0, 0, 1, 1}
 *         비트마스킹 풀이와 마찬가지로 1로 표시된 인덱스의 값만 연산에 포함하면 됨
 */
int main() {
    int l, c;
    vector<char> alpha;
    vector<bool> comb;

    //모음 저장
    is_vowel['a' - 'a'] = is_vowel['e' - 'a'] = is_vowel['i' - 'a'] = is_vowel['o' - 'a'] = is_vowel['u' - 'a'] = true;

    //입력
    cin >> l >> c;
    alpha.assign(c, ' ');
    comb.assign(c, false);
    for (int i = 0; i < c; i++)
        cin >> alpha[i];

    //연산 & 출력

    //인덱스 0부터 l개의 원소를 true로 셋팅
    for (int i = 0; i < l; i++)
        comb[i] = true;
    sort(alpha.begin(), alpha.end()); //알파벳 사전순 정렬
    do {
        if (promising(l, alpha, comb)) //가능성 있는 암호라면 출력
            cout << charToString(alpha, comb) << '\n';
    } while (prev_permutation(comb.begin(), comb.end()));
}