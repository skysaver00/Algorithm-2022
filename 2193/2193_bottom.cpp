#include <iostream>

using namespace std;
long long ans[91][2];

int main() {
    int n;
    cin >> n;

    ans[1][1] = 1;
    for(int i = 2; i <= n; i++) {
        ans[i][1] = ans[i - 1][0];
        ans[i][0] = ans[i - 1][0] + ans[i - 1][1];
    }
    cout << ans[n][0] + ans[n][1];
}