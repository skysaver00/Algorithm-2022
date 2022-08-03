#include <iostream>
#include <stack>

using namespace std;

int arr[1000001];
int ans[1000001];
int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) cin >> arr[i];

    stack <int> stk;
    stk.push(0);
    for(int i = 1; i < n; i++) {
        if(stk.empty()) stk.push(i);

        while(!stk.empty() && arr[stk.top()] < arr[i]) {
            ans[stk.top()] = arr[i];
            stk.pop();
        }
        stk.push(i);
    }
    
    while(!stk.empty()) {
        ans[stk.top()] = -1;
        stk.pop();
    }

    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}