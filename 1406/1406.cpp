#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<char> left;
    stack<char> right;

    string word;
    cin >> word;
    int len = word.length();

    for(int i = 0; i < len; i++) {
        left.push(word[i]);
    }

    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        char one, two;
        cin >> one;

        if(one == 'L') {
            if(left.empty()) continue;
            else {
                right.push(left.top());
                left.pop();
            }
        }
        else if(one == 'D') {
            if(right.empty()) continue;
            else {
                left.push(right.top());
                right.pop();
            }
        }
        else if(one == 'B') {
            if(left.empty()) continue;
            else left.pop();
        }
        else {
            cin >> two;
            left.push(two);
        }
    }

    while(!left.empty()) {
        right.push(left.top());
        left.pop();
    }

    while(!right.empty()) {
        cout << right.top();
        right.pop();
    }

    return 0;
}