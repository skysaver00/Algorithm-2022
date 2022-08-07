#include <iostream>

using namespace std;

int ans[1001];

int dp(int x) {
    if(x == 1) return 1;
    if(x == 2) return 3;
    if(ans[x] > 0) return ans[x];
    ans[x] = (dp(x - 1) + 2 * dp(x - 2)) % 10007;
    return ans[x];
}

int main() {
    int n;
    cin >> n;
    cout << dp(n);
}