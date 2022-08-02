#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack <char> stack;
    cin.ignore();

    string str;
    string value;
    getline(cin, str);

    int len = str.length();

    int flag = 0;
    for(int i = 0; i < len; i++) {
        if(str[len] == '<') {
            flag == 1;
            value += str[len];
            continue;
        }
        else if(str[len] == '>') {
            flag == 0;
            value += str[len];
            cout << value;
            value.clear();
        }

        if(flag == 1) {
            value += str[len];
        } else if(flag == 0) {
            if(str[len] != ' ') {
                stack.push(str[len]);
            } else {
                while(!stack.empty()) {
                    cout << stack.top();
                    stack.pop();
                }
                cout << " ";
            }
        }
    }

    if(flag == 1) {
        cout << "\n";
    } else if(flag == 0) {
        while(!stack.empty()) {
            cout << stack.top();
            stack.pop();
        }
        cout << " ";
    }

    return 0;
}