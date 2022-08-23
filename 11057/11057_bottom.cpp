#include <iostream>

using namespace std;
int arr[1000][10];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < 10; i++) arr[0][i] = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k <= j; k++) {
                arr[i][j] = (arr[i][j] + arr[i - 1][k]) % 10007;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 10; i++) {
        ans = ans + arr[n - 1][i];
        ans %= 10007;
    }
    cout << ans;
}