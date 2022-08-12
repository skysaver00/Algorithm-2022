#include <iostream>

using namespace std;
int ans[100001][3];

int main() {
    int n;
    cin >> n;
    ans[1][0] = 1;
    ans[1][1] = 1;
    ans[1][2] = 1;
    for(int i = 2; i <= n; i++) {
        ans[i][0] = (ans[i - 1][0] + ans[i - 1][1] + ans[i - 1][2]) % 9901;
        ans[i][1] = (ans[i - 1][0] + ans[i - 1][2]) % 9901;
        ans[i][2] = (ans[i - 1][0] + ans[i - 1][1]) % 9901;
    }
    cout << (ans[n][0] + ans[n][1] + ans[n][2]) % 9901;
}