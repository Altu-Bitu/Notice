#include <iostream>
#include <vector>
#include <deque>

using namespace std;

//그라운드에 있는 카드를 덱으로 옮기는 함수
void moveCard(deque<int> &deck, deque<int> &ground) {
    while (!ground.empty()) {
        deck.push_back(ground.back());
        ground.pop_back();
    }
}

//게임을 진행하는 함수
pair<int, int> playGame(int m, vector<deque<int>> &deck, vector<deque<int>> &ground) {
    bool turn = false; //도도부터 시작

    while (m--) {
        //이번 턴의 사람이 카드 뒤집어서 그라운드에 올려놓기
        int card = deck[turn].front();
        ground[turn].push_front(card);
        deck[turn].pop_front();

        //게임 진행 도중 둘 중 한 명의 덱에 있는 카드의 수가 0개가 되는 즉시 게임 종료
        if (deck[turn].empty())
            break;

        //이번에 종을 칠 사람
        int bell = -1;
        if (card == 5)
            bell = 0;
        else if (!ground[0].empty() && !ground[1].empty() && (card + ground[!turn].front() == 5))
            bell = 1;

        if (bell != -1) { //누군가가 종을 쳤다면
            moveCard(deck[bell], ground[!bell]);
            moveCard(deck[bell], ground[bell]);
        }
        turn = !turn; //차례 바꾸기
    }
    return make_pair(deck[0].size(), deck[1].size());
}

/**
 * 1. 카드 덱과 그라운드의 카드를 관리하기 위해 덱 사용
 * 2. 게임을 진행하던 도중 언제든지 누군가의 카드 덱이 비게되면 게임을 종료
 */
int main() {
    int n, m, num1, num2;
    vector<deque<int>> deck(2), ground(2);

    cin >> n >> m;
    while (n--) {
        cin >> num1 >> num2;
        deck[0].push_front(num1);
        deck[1].push_front(num2);
    }

    pair<int, int> result = playGame(m, deck, ground);

    if (result.first == result.second)
        cout << "dosu\n";
    else if (result.first > result.second)
        cout << "do\n";
    else if (result.first < result.second)
        cout << "su\n";
}