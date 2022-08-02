#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack <char> stack;

    string str;
    string value = "";
    getline(cin, str);
    str += "\n";

    int len = str.length();

    int flag = 0;
    for(int i = 0; i < len - 1; i++) {
        if(str[i] == '<') {
            if(!stack.empty()) {
                while(!stack.empty()) {
                    cout << stack.top();
                    stack.pop();
                }
            }
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
            continue;
        }

        if(flag == 1) {
            value += str[i];
        } else if(flag == 0) {
            if(str[i] == ' ' || str[i] == '<') {
                while(!stack.empty()) {
                    cout << stack.top();
                    stack.pop();
                }
                cout << " ";
            } else {
                stack.push(str[i]);
            }
        }
    }

    if(flag == 1) {
    } else if(flag == 0) {
        while(!stack.empty()) {
            cout << stack.top();
            stack.pop();
        }
        cout << " ";
    }
    cout << "\n";

    return 0;
}