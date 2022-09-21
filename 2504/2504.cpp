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
            if(stk.empty() || stk.top() == '[') {
                cout << "0\n";
                return 0;
            }
            vec.push_back({sz - 1, 2});
            stk.pop();
        } else if(now = ']') {
            if(stk.empty() || stk.top() == '(') {
                cout << "0\n";
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
    for(int i = 1; i < sz; i++) {
        int start = i;
        if(vec[i - 1].first > vec[i].first) {
            while(start != -1) {
                start -= 1;
                if(vec[start].first == vec[i].first) break;
            }
        }

        start++;
        for(int j = start; j < i; j++) {
            vec[j].second *= vec[i].second;
        }
    }

    int ans = vec[0].second;

    for(int i = 1; i < sz; i++) {
        if(vec[i].first >= vec[i - 1].first) ans += vec[i].second;
    }
    cout << ans << '\n';
    return 0;
}