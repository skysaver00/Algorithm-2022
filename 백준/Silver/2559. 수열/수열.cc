#include <iostream>

using namespace std;
int arr[100003];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n, k;
    cin >> n >> k;

    int val;
    cin >> val;
    arr[1] = val;
    for(int i = 2; i <= n; i++) {
        cin >> val;
        arr[i] = arr[i - 1] + val;
    }

    int ans = -1000000000;
    for(int i = k; i <= n; i++) {
        int sub = arr[i] - arr[i - k];
        if(sub > ans) ans = sub;
    }
    cout << ans;
    return 0;
}