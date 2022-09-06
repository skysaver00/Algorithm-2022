#include <iostream>

using namespace std;
int arr[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    int low, high, mid;
    low = 0;
    high = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(high < arr[i]) high = arr[i];
    }

    long long ans = 0;
    while(low <= high) {
        mid = (low + high) / 2;
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] >= mid) sum += (arr[i] - mid);
        }
        if(sum >= m) {
            if(ans < mid) ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    cout << ans << '\n';
}