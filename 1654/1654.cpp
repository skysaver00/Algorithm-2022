#include <iostream>

using namespace std;
int arr[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, n;
    cin >> k >> n;

    int maxi = -1;
    for(int i = 0; i < k; i++) {
        cin >> arr[i];
        if(maxi < arr[i]) maxi = arr[i];
    }

    int left = 1;
    int right = maxi;
    int ans = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
        int lan = 0;
        for(int i = 0; i < k; i++) lan += (arr[i] / mid);
        if(lan < n) {
            right = mid - 1;
        } else {
            ans = mid;
            left = mid + 1;
        }
    }
    cout << ans << '\n';
}