#include <iostream>

using namespace std;

long long ans[101][10];

int dp(int x, int y) {
    if(x == 1) return ans[x][y];
    if(ans[x][y] > 0) return ans[x][y];

    if(y == 0) ans[x][y] = dp(x - 1, 1);
    else if(y == 9) ans[x][y] = dp(x - 1, 8);
    else ans[x][y] = ((dp(x - 1, y - 1) + dp(x - 1, y + 1)) % 1000000000);

    return ans[x][y];
}

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= 9; i++) ans[1][i] = 1;
    for(int i = 0; i <= 9; i++) dp(n, i);

    long long val = 0;
    for(int i = 0; i <= 9; i++) val = (val + ans[n][i]) % 1000000000;
    cout << val << "\n";

    return 0;
}