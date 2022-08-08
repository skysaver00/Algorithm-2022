#include <iostream>

using namespace std;
long long ans[10001];

int main() {
    int n;
    cin >> n;

    ans[1] = 1;
    for(int i = 2; i <= n; i++) ans[i] = ans[i - 1] + ans[i - 2];
    cout << ans[n];
}