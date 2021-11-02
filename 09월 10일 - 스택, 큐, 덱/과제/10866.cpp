#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 10001; //덱의 최대 크기

int front_pointer = 0, rear_pointer = 0;
vector<int> deque_vec(SIZE);

bool empty() {
    return front_pointer == rear_pointer;
}

bool full() {
    return (rear_pointer + 1) % SIZE == front_pointer;
}

void push_front(int num) { //덱에 추가된 것
    deque_vec[front_pointer] = num;
    front_pointer = (front_pointer + SIZE - 1) % SIZE;
}

void push_back(int num) {
    rear_pointer = (rear_pointer + 1) % SIZE;
    deque_vec[rear_pointer] = num;
}

int pop_front() {
    front_pointer = (front_pointer + 1) % SIZE;
    return deque_vec[front_pointer];
}

int pop_back() { //덱에 추가된 것
    int num = deque_vec[rear_pointer];
    rear_pointer = (rear_pointer + SIZE - 1) % SIZE;
    return num;
}

int size() {
    int tmp = (rear_pointer - front_pointer);
    if (tmp < 0) //rear = 1, front = 3일 때
        tmp += SIZE;
    return tmp;
}

int front() {
    int tmp = (front_pointer + 1) % SIZE;
    return deque_vec[tmp];
}

int back() {
    return deque_vec[rear_pointer];
}

/**
 * 라이브러리 : #include <deque>
 */
int main() {
    int n, num;
    string cmd;

    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == "push_front") {
            cin >> num;
            if (!full()) //덱 라이브러리 사용시엔 필요없음
                push_front(num);
            continue;
        }
        if (cmd == "push_back") {
            cin >> num;
            if (!full()) //덱 라이브러리 사용시엔 필요없음
                push_back(num);
            continue;
        }
        if (cmd == "pop_front") {
            if (empty()) //런타임 에러 방지
                cout << -1 << '\n';
            else
                cout << pop_front() << '\n';
            continue;
        }
        if (cmd == "pop_back") {
            if (empty()) //런타임 에러 방지
                cout << -1 << '\n';
            else
                cout << pop_back() << '\n';
            continue;
        }
        if (cmd == "size") {
            cout << size() << '\n';
            continue;
        }
        if (cmd == "empty") {
            cout << empty() << '\n';
            continue;
        }
        if (cmd == "front") {
            if (empty()) //런타임 에러 방지
                cout << -1 << '\n';
            else
                cout << front() << '\n';
            continue;
        }
        if (cmd == "back") {
            if (empty()) //런타임 에러 방지
                cout << -1 << '\n';
            else
                cout << back() << '\n';
            continue;
        }
    }
}