#include <iostream>

using namespace std;
int ans[201][201];

int main() {
    int n, k;
    cin >> n >> k;

    ans[0][0] = 1;
    for(int i = 1; i <= k; i++) {
        for(int j = 0; j <= n; j++) {
            for(int l = 0; l <= j; l++) {
                ans[i][j] += ans[i - 1][j - l];
                ans[i][j] %= 1000000000;
            }
        }
    }
    cout << ans[k][n];
}