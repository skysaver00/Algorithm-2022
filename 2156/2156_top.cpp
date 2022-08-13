#include <iostream>

using namespace std;
int ans[10001];
bool check[10001];
int arr[10001];

int dp(int x) {
    if(x == 1) return arr[1];
    if(x == 2) return arr[1] + arr[2];
    if(check[x] == true) return ans[x];

    if(x >= 3) ans[x] = max(max(dp(x - 2), dp(x - 3) + arr[x - 1]) + arr[x], dp(x - 1));
    check[x] = true;
    return ans[x];
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    cout << dp(n);
}