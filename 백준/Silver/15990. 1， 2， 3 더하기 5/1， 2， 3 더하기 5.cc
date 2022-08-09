#include <iostream>

using namespace std;
long long ans[100001][3];

int main() {
    int t;
    cin >> t;

    ans[1][1] = 1;
    ans[2][2] = 1;
    ans[3][3] = 1;

    for(int i = 3; i <= 100000; i++) {
        ans[i][1] += (ans[i - 1][2] + ans[i - 1][3]) % 1000000009;
        ans[i][2] += (ans[i - 2][1] + ans[i - 2][3]) % 1000000009;
        ans[i][3] += (ans[i - 3][1] + ans[i - 3][2]) % 1000000009;
    }

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << (ans[n][1] + ans[n][2] + ans[n][3]) % 1000000009 << "\n";
    }
    return 0;
}