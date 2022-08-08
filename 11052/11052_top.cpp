#include <iostream>

using namespace std;

int ans[10001];
int arr[10001];

int dp(int x) {
    if(x == 1) return arr[1];
    if(ans[x] > 0) return ans[x];

    for(int i = 1; i <= x; i++) {
        int temp = arr[i] + dp(x - i);
        if(temp > ans[x]) ans[x] = temp;
    }
    return ans[x];
}

int main() {
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) cin >> arr[i];
    cout << dp(n);
}