#include <iostream>

using namespace std;
long long ans[1000001];

long long dp(int x) {
    if(x == 1) return 1;
    else if(x == 2) return 2;
    else if(x == 3) return 4;

    if(ans[x] > 0) return ans[x];
    ans[x] = (dp(x - 1) + dp(x - 2) + dp(x - 3)) % 1000000009;
    return ans[x];
}

int main() {
    int t;
    cin >> t;
    dp(1000000);
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << dp(n) << "\n";
    }
}