#include <iostream>

using namespace std;
int ans[10001];
int arr[10001];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    ans[1] = arr[1];
    ans[2] = arr[1] + arr[2];
    for(int i = 3; i <= n; i++) {
        ans[i] = max(ans[i - 1], ans[i - 2] + arr[i]);
        ans[i] = max(ans[i], ans[i - 3] + arr[i - 1] + arr[i]);
    }
    cout << ans[n];
}