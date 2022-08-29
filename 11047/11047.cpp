#include <iostream>

using namespace std;
int coin[11];

int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> coin[i];
    int ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        ans += (k / coin[i]);
        k = k - ((k / coin[i]) * coin[i]);
    }
    cout << ans;
}