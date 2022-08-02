#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack <char> stack;
    cin.ignore();

    string str;
    string value = "";
    getline(cin, str);

    int len = str.length();

    int flag = 0;
    for(int i = 0; i < len; i++) {
        if(str[i] == '<') {
            flag = 1;
            value += str[i];
            continue;
        }
        else if(str[i] == '>') {
            flag = 0;
            value += str[i];
            cout << value;
            value.clear();
            value = "";
        }

        if(flag == 1) {
            value += str[i];
        } else if(flag == 0) {
            if(str[i] != ' ') {
                stack.push(str[i]);
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