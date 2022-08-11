#include <iostream>

using namespace std;
long long ans[1000001];

int main() {
    int t;
    cin >> t;

    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 4;
    for(int i = 4; i <= 1000000; i++) ans[i] = (ans[i - 1] + ans[i - 2] + ans[i - 3]) % 1000000009;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << ans[n] << "\n";
    }
}