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
    int value = arr[0];
    for(int i = 1; i < n; i++) {
        if(value < arr[i]) {
            while(!stk.empty()) {
                ans[stk.top()] = arr[i];
                stk.pop();
            }
            value = arr[i];
            stk.push(i);
        } else if(value >= arr[i]) {
            stk.push(i);
        }

        for(int j = 0; j <= i; j++) {
            cout << ans[j] << ' ';
        } cout << "\n";
    }
    cout << "\n";

    return 0;
}