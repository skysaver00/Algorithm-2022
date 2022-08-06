#include <iostream>
#include <stack>

using namespace std;

int arr[1000001];
int num[1000001];
int ans[1000001];

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        num[arr[i]]++;
    }

    stack<int> sta;
    sta.push(0);

    for(int i = 1; i < n; i++) {
        if(sta.empty()) sta.push(i);
        
        while(!sta.empty() && num[arr[sta.top()]] < num[arr[i]]) {
            ans[sta.top()] = arr[i];
            sta.pop();
        }
        sta.push(i);
    }

    while(!sta.empty()) {
        ans[sta.top()] = -1;
        sta.pop();
    }

    for(int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}