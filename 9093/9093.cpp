#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    stack<char> maker;

    int t;
    string str;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> str;
        int len = str.length();
        for(int j = 0; j < len; j++) {
            maker.push(str[j]);
        }
        while(!maker.empty()) {
            cout << maker.top();
            maker.pop();
        }
    }
    return 0;
}