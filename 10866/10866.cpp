#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> deque;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;

        if(str == "push_front") {
            int num;
            cin >> num;

            deque.push_front(num);
        } else if(str == "push_back") {
            int num;
            cin >> num;

            deque.push_back(num);
        } else if(str == "pop_front") {
            if(deque.empty()) cout << "-1\n";
            else {
                cout << deque.front() << "\n";
                deque.pop_front();
            }
        } else if(str == "pop_back") {
            if(deque.empty()) cout << "-1\n";
            else {
                cout << deque.back() << "\n";
                deque.pop_back();
            }
        } else if(str == "size") {
            cout << deque.size() << "\n";
        } else if(str == "empty") {
            if(deque.empty()) cout << "1\n";
            else cout << "0\n";
        } else if(str == "front") {
            if(deque.empty()) cout << "-1\n";
            else cout << deque.front() << "\n";
        } else if(str == "back") {
            if(deque.empty()) cout << "-1\n";
            else cout << deque.back() << "\n";
        }
    }

    return 0;
}