#include <iostream>

using namespace std;

int ans[10001];
int arr[10001];

int dp(int x) {
    if(x == 1) return arr[1];
    if(ans[x] < 100000000) return ans[x];

    for(int i = 1; i <= x; i++) {
        int temp = arr[i] + dp(x - i);
        if(temp < ans[x]) ans[x] = temp;
    }
    return ans[x];
}

int main() {
    fill_n(ans, 10000, 1000000000);
    int n;
    cin >> n;

    ans[0] = 0;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    cout << dp(n);
}