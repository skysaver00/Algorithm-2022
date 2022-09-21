#include <iostream>
#include <stack>
#include <vector>

using namespace std;
string str;
stack <int> stk;
int temp = 1;
int sum = 0;

int main() {
    cin >> str;

    int len = str.length();
    for(int i = 0; i < len; i++) {
        int sz = stk.size();
        char now = str[i];
        if(now == '(') {
            stk.push('(');
            temp *= 2;
        } else if(now == '[') {
            stk.push('[');
            temp *= 3;
        } else if(now == ')') {
            if(stk.empty() || stk.top() != '(') {
                cout << "0\n";
                return 0;
            }
            if(str[i - 1] == '(') {
                sum += temp;
            }
            stk.pop();
            temp /= 2;
        } else if(now = ']') {
            if(stk.empty() || stk.top() != '[') {
                cout << "0\n";
                return 0;
            }
            if(str[i - 1] == '[') {
                sum += temp;
            }
            stk.pop();
            temp /= 3;
        }
    }

    if(!stk.empty()) {
        cout << "0\n";
        return 0;
    } else cout << sum;
}