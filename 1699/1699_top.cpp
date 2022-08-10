#include <iostream>

using namespace std;
int ans[100001];

int dp(int x) {
    if(ans[x] > 0) return ans[x];
    int temp = dp()
}

int main() {
    int n;
    cin >> n;

    for(int i = 1; i * i <= n; i++) ans[i] = 1;
    for(int i = 1; i <= n; i++) dp(i);
}