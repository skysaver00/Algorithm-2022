#include <iostream>
#include <stack>

using namespace std;
int arr[500001];
stack <int> stk;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    int ans = 0;
    stk.push(arr[0]);
    for(int i = 1; i < n; i++) {
        while(!stk.empty()) {
            int top = stk.top();
            if(top < arr[i]) {
                ans++;
                stk.pop();
            } else break;
        }

        if(!stk.empty()) ans++;
        stk.push(arr[i]);
    }
    cout << ans << '\n';
}