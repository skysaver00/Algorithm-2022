#include <iostream>

using namespace std;
int ans[10001];
int arr[10001];

int getmin(int x, int y) {
    if(x < y) return x;
    else return y;
}

int main() {
    fill_n(ans, 10000, 100000000);
    ans[0] = 0;
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> arr[i];

    ans[1] = arr[1];
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            ans[i] = getmin(arr[j] + ans[i - j], ans[i]);
        }
    }

    cout << ans[n] << '\n';
}