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

    long long left = 1;
    long long right = maxi;
    long long ans = 0;
    while(left <= right) {
        long long mid = (left + right) / 2;
        long long lan = 0;
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