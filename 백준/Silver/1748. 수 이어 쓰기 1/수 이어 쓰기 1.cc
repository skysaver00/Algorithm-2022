#include <iostream>

using namespace std;
long long n;
int arr[10] = {9, 90, 900, 9000, 90000, 900000, 9000000, 90000000, 1};

int main() {
    cin >> n;
    int digit = 10;
    int ans = 0;
    int one = 1;
    int now = 0;
    while(digit <= 100000000) {
        if(n >= digit) {
            ans += (arr[now]) * one;
            one++;
            now++;
            digit *= 10;
        }
        else {
            ans += (n - (digit / 10) + 1) * one;
            break;
        }
    }
    if(n == 100000000) ans += 9;
    cout << ans << "\n";
}