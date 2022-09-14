#include <iostream>

using namespace std;
int a[10001];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    int sum = a[0];
    int left, right;
    left = 0; right = 0;
    while(left < n && right < n) {
        if(sum == m) ans++;
        if(sum <= m) {
            right++;
            sum += a[right];
        } else {
            sum -= a[left];
            left++;
        }
    }

    cout << ans << '\n';
    return 0;
}