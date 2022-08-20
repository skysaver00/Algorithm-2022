#include <iostream>

using namespace std;
int n;
int arr[10] = {9, 90, 900, 9000, 90000, 900000, 9000000, 90000000, 1};

int main() {
    cin >> n;
    int digit = 10;
    int ans = 0;
    int one = 1;
    int now = 0;
    while(digit <= 100000000) {
        cout << one << ' ' << now << "\n";
        if(n > digit) {
            ans += (arr[now]) * one;
            one++;
            now++;
            digit *= 10;
        }
        else {
            cout << "Yes";
            cout << one << "\n";
            
            ans += (n - (digit / 10) + 1) * one;
            break;
        }
        cout << ans << "\n";
    }
    cout << ans << "\n";
}