//
// Created by iw040 on 2021-09-10.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 10001;

int front_pointer = 0, rear_pointer = 0;
vector<int> queue_vec(SIZE);

//empty
bool empty() {
    return front_pointer == rear_pointer;
}

//full
bool full() {
    return (rear_pointer + 1) % SIZE == front_pointer;
}

//push
void push(int k) {
    rear_pointer = (rear_pointer + 1) % SIZE;
    queue_vec[rear_pointer] = k;
}

//pop
int pop() {
    front_pointer = (front_pointer + 1) % SIZE;
    return queue_vec[front_pointer];
}

//size
int size() { //rear = 1, front = 2
    int tmp = (rear_pointer - front_pointer);
    if (tmp < 0)
        tmp += SIZE;
    return tmp;
}

//front
int front() {
    int tmp = (front_pointer + 1) % SIZE;
    return queue_vec[tmp];
}

//back
int back() {
    return queue_vec[rear_pointer];
}

int main() {
    int n, k;
    string cmd;
    queue<int> q;

    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> k;
//            if (!full()) //라이브러리 사용시 필요 없음
//                q.push(k);
            q.push(k);
            continue;
        }
        if (cmd == "pop") {
            if (q.empty())
                cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
            continue;
        }
        if (cmd == "size") {
            cout << q.size() << '\n';
            continue;
        }
        if (cmd == "empty") {
            cout << q.empty() << '\n';
            continue;
        }
        if (cmd == "front") {
            if (q.empty())
                cout << -1 << '\n';
            else
                cout << q.front() << '\n';
            continue;
        }
        if (cmd == "back") {
            if (q.empty())
                cout << -1 << '\n';
            else
                cout << q.back() << '\n';
            continue;
        }
    }
    /*
     * 큐 순회
     */
    while (!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }
}