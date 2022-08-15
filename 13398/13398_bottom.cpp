#include <iostream>

using namespace std;
int lef[100001];
int rig[100001];
int arr[100001];
int ans;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    lef[0] = arr[0];
    for(int i = 1; i < n; i++) lef[i] = max(arr[i], lef[i - 1] + arr[i]);

    rig[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; i--) rig[i] = max(arr[i], rig[i + 1] + arr[i]);

    ans = lef[0];
    for(int i = 1; i < n - 1; i++) {
        if(ans < lef[i]) ans = lef[i];
        if(ans < lef[i - 1] + rig[i + 1]) ans = lef[i - 1] + rig[i + 1];
    }
    if(ans < lef[n - 1]) ans = lef[n - 1];
    cout << ans;
}