#include <iostream>

using namespace std;
int arr[30][2];
int ans[30];
int val;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i][0] >> arr[i][1];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) val = max(val, ans[i]);
        if(i > 0) ans[i] = max(val, ans[i]);

        if(i + arr[i][0] <= n) {
            ans[i + arr[i][0]] = max(ans[i + arr[i][0]], ans[i] + arr[i][1]);
            //cout << i << ' ' << arr[i][0] << ' ' << ans[i + arr[i][0]] << ' ' << ans[i] << ' ' << arr[i][1] << "\n";
        }
    }

    int maximum = ans[0];
    for(int i = 1; i <= n; i++) maximum = max(maximum, ans[i]);
    cout << maximum;
}