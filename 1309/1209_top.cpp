#include <iostream>

using namespace std;
int ans[100001][3];

int dp(int x, int y) {
    if(x == 1) return 1;
    if(ans[x][y] > 0) return ans[x][y];

    ans[x][0] = (dp(x - 1, 0) + dp(x - 1, 1) + dp(x - 1, 2)) % 9901;
    ans[x][1] = (dp(x - 1, 0) + dp(x - 1, 2)) % 9901;
    ans[x][2] = (dp(x - 1, 0) + dp(x - 1, 1)) % 9901;

    return ans[x][y];
}

int main() {
    int n;
    cin >> n;
    cout << (dp(n, 0) + dp(n, 1) + dp(n, 2)) % 9901;
}