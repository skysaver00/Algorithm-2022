#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string sentence;
    stack<char> stack;

    int t;
    cin >> t;
    cin.ignore();
    for(int i = 0; i < t; i++) {
        getline(cin, sentence);
        sentence += '\n';

        int len = sentence.length();
        int flag = 0;
        for(int j = 0; j < len - 1; j++) {
            if(sentence[j] == ' ') {
                if(flag == 0) {
                    flag++;
                } else {
                    cout << ' ';
                }
                while(!stack.empty()) {
                    cout << stack.top();
                    stack.pop();
                }
            } else {
                stack.push(sentence[j]);
            }
        }
        if(flag != 0) cout << " ";
        while(!stack.empty()) {
            cout << stack.top();
            stack.pop();
        }
        cout << "\n";
        flag = 0;
    }

    return 0;
}