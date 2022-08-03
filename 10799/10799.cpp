#include <iostream>

using namespace std;

int main() {
    string bar;
    cin >> bar;

    int len = bar.length();

    int now = -1;
    int ans = 0;
    for(int i = 0; i < len; i++) {
        if(bar[i] == '(') {
            now++;
        } else if(bar[i] == ')') {
            if(bar[i - 1] == '(') {
                ans += now;
                now -= 1;
            } else if(bar[i - 1] == ')') {
                ans += 1;
                now -= 1;
            }
        }
    }

    cout << ans;
    return 0;
}