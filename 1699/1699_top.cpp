#include <iostream>

using namespace std;
int ans[100001];

int dp(int x) {
    if(ans[x] > 0) return ans[x];
    for(int i = 1; i * i <= x; i++) {
        int temp = dp(x - i * i) + 1;
        if(ans[x] == 0) ans[x] = temp;
        if(temp < ans[x]) ans[x] = temp;
    }
    return ans[x];
}

int main() {
    int n;
    cin >> n;

    for(int i = 1; i * i <= n; i++) ans[i * i] = 1;
    for(int i = 1; i <= n; i++) dp(i);
    cout << dp(n);
}