#include <iostream>

using namespace std;

long long ans[91][2];

long long dp(long long x, long long y) {
    if(x == 1) return ans[x][y];
    if(ans[x][y] > 0) return ans[x][y];

    ans[x][0] = dp(x - 1, 0) + dp(x - 1, 1);
    ans[x][1] = dp(x - 1, 0);

    return ans[x][y];
}

int main() {
    int n;
    cin >> n;

    ans[1][1] = 1;
    cout << dp(n, 0) + dp(n, 1);

    return 0;
}