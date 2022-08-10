#include <iostream>

using namespace std;
int ans[100001];

int getmin(int x, int y) {
    if(x < y) return x;
    else return y;
}

int main() {
    fill_n(ans, 100000, 1000000);
    int n;
    cin >> n;

    for(int i = 1; i * i <= n; i++) ans[i * i] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j * j <= i; j++) {
            ans[i] = getmin(ans[i - j * j] + 1, ans[i]);
        }
    }
    cout << ans[n];
}