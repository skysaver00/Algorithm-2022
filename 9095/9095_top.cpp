#include <iostream>

using namespace std;

int ans[14];
int dp(int x) {
    if(x == 1) return 1;
    if(x == 2) return 2;
    if(x == 3) return 4;
    if(ans[x] > 0) return ans[x];

    ans[x] = dp(x - 1) + dp(x - 2) + dp(x - 3);
    return ans[x];
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << dp(n) << "\n";
    }
    return 0;
}