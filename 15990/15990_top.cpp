#include <iostream>

using namespace std;

long long ans[100004][4];

long long dp(int x, int y) {
    if(x < 0) return 0;
    if(ans[x][y] > 0) return ans[x][y];

    if(y == 1) {
        ans[x][y] = dp(x - 1, 2) + dp(x - 1, 3);
        ans[x][y] %= 1000000009;
    } else if(y == 2) {
        ans[x][y] = dp(x - 2, 1) + dp(x - 2, 3);
        ans[x][y] %= 1000000009;
    } else {
        ans[x][y] = dp(x - 3, 1) + dp(x - 3, 2);
        ans[x][y] %= 1000000009;
    }

    return ans[x][y];
}

int main() {
    int t;
    cin >> t;
    ans[1][1] = ans[2][2] = ans[3][3] = 1;
    dp(100000, 1);
    dp(100000, 2);
    dp(100000, 3);

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        cout << (dp(n, 1) + dp(n, 2) + dp(n, 3)) % 1000000009 << "\n";
    }
}