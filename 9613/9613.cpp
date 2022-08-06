#include <iostream>

using namespace std;

int getgcd(int j, int k) {
    while(k != 0) {
        int temp = j % k;
        j = k;
        k = temp;
    }

    return j;
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;

        int arr[101];
        long long ans = 0;

        for(int j = 0; j < n; j++) cin >> arr[j];

        for(int j = 0; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                ans += getgcd(arr[j], arr[k]);
            }
        }
        
        cout << ans << "\n";
    }
}