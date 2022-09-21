#include <iostream>
#include <stack>
#include <vector>

using namespace std;
string str;
stack <char> stk;
vector <pair<int, int>> vec;

int main() {
    cin >> str;

    int len = str.length();
    int ans = 0;
    for(int i = 0; i < len; i++) {
        int sz = stk.size();
        char now = str[i];
        if(now == '(') {
            stk.push('(');
            continue;
        } else if(now == '[') {
            stk.push('[');
            continue;
        }

        if(now == ')') {
            if(stk.top() == '[') {
                cout << 0 << '\n';
                return 0;
            }
            vec.push_back({sz - 1, 2});
            stk.pop();
        } else if(now = ']') {
            if(stk.top() == '(') {
                cout << 0 << '\n';
                return 0;
            }
            vec.push_back({sz - 1, 3});
            stk.pop();
        }
    }

    if(!stk.empty()) {
        cout << 0 << '\n';
        return 0;
    }

    int val[35];
    fill_n(val, 30, 1);

    int sz = vec.size();
    int start = 0;
    int now;
    for(int i = 0; i < sz; i++) {
        if()
        cout << vec[i].first << ' ' << vec[i].second << '\n';
    }
    return 0;
}