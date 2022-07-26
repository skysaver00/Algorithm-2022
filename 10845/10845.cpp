#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> queue;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;

        if(str == "push") {
            int num;
            cin >> num;

            queue.push(num);
        } else if(str == "pop") {
            if(queue.empty()) cout << "-1\n";
            else {
                cout << queue.front() << "\n";
                queue.pop();
            }
        } else if(str == "front") {
            if(queue.empty()) cout << "-1\n";
            else {
                cout << queue.front() << "\n";
            }
        } else if(str == "back") {
            if(queue.empty()) cout << "-1\n";
            else {
                cout << queue.back() << "\n";
            }
        } else if(str == "size") {
            cout << queue.size() << "\n";
        } else if(str == "empty") {
            if(queue.empty()) cout << "1\n";
            else cout << "0\n";
        }
    }
}