#include <iostream>

using namespace std;

long long ans[101][10];

int main() {
    for(int i = 1; i <= 9; i++) ans[1][i] = 1;

    int n;
    cin >> n;

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= 9; j++) {
            if(j >= 1) ans[i][j] += (ans[i - 1][j - 1] % 1000000000);
            if(j <= 8) ans[i][j] += (ans[i - 1][j + 1] % 1000000000);
        }
    }

    long long val = 0;
    for(int i = 0; i <= 9; i++) val += ans[n][i] % 1000000000;
    val %= 1000000000;
    cout << val;
}