#include <iostream>
#include <stack>

using namespace std;
int arr[1000001];
int ans[1000001];

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) cin >> arr[i];
    
    stack<int> stack;
    stack.push(0);
    for(int i = 1; i < n; i++) {
        if(stack.empty()) stack.push(i);

        while(!stack.empty() && arr[stack.top()] < arr[i]) {
            ans[stack.top()] = arr[i];
            stack.pop();
        }

        stack.push(i);
    }
    
    while(!stack.empty()) {
        ans[stack.top()] = -1;
        stack.pop();
    }

    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << "\n";

    return 0;
}