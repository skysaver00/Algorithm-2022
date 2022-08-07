#include <iostream>

using namespace std;

int ans[1000005];

int dp(int x) {
    if(x == 1) return 0;
    if(ans[x] > 0) return ans[x];
    ans[x] = dp(x - 1) + 1;
    if(x % 2 == 0) {
        int temp = dp(x / 2) + 1;
        if(ans[x] > temp) ans[x] = temp;
    }
    if(x % 3 == 0) {
        int temp = dp(x / 3) + 1;
        if(ans[x] > temp) ans[x] = temp;
    }
    return ans[x];
}

int main() {
    int x;
    cin >> x;
    cout << dp(x);
    
    return 0;
}