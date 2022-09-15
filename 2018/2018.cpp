#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int left, right;
    left = 1;
    right = 1;
    int sum = 1;
    int ans = 0;

    while(left <= n) {
        if(sum == n) ans++;

        if(sum < n) {
            right++;
            sum += right;
        } else {
            sum -= left;
            left++;
        }
    }
    cout << ans << '\n';
    return 0;
}