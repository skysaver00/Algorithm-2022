#include <iostream>

using namespace std;
int arr[1000001];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) cin >> arr[i];
    int left, right;
    int ans, now;
    now = 0;
    ans = 99999999;
    left = 0;
    right = 0;
    if(arr[left] == 1) now++;
    else {
        while(arr[left] != 1) {
            left++;
            right++;
        }
        now++;
    }

    while(right < n) {
        if(now < k) right++;
        else {
            int sub = right - left;
            if(sub < ans) ans = sub;
            left++;
            right++;
            while(arr[left] != 1) left++;
            now--;
        }
        if(arr[right] == 1) now++;
    }

    if(ans < 9000000) cout << ans + 1;
    else cout << -1;
    return 0;
}