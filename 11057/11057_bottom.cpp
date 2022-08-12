#include <iostream>

using namespace std;
int ans[1001][10];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i <= 9; i++) ans[1][i] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= 9; j++) {
            for(int k = 0; k <= j; k++) {
                ans[i][j] += ans[i - 1][k];
                ans[i][j] %= 10007;
            }
        }
    }
    int val = 0;
    for(int i = 0; i <= 9; i++) {
        val += ans[n][i];
        val %= 10007;
    }
    cout << val;
}