#include <iostream>

using namespace std;

int ans[10005];
int arr[10005];

int getmax(int x, int y) {
    if(x > y) return x;
    else return y;
}

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> arr[i];

    ans[1] = arr[1];
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            ans[i] = getmax(arr[j] + ans[i - j], ans[i]);
        }
    }
    cout << ans[n] << "\n";
    return 0;
}