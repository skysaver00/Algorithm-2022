#include <iostream>

using namespace std;
long long a[5001];
long long arr[5001][5001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i = 1; i < n + 1; i++) cin >> a[i];
    for(int i = 1; i < n + 1; i++) {
        arr[i][n] = 0;
        if(a[n] < i) arr[i][n - 1] = 1;
        else arr[i][n - 1] = 0;

        for(int j = n - 2; j > 0; j--) {
            if(a[j + 1] < i) arr[i][j] = arr[i][j + 1] + 1;
            else arr[i][j] = arr[i][j + 1];
        }
    }

    long long ans = 0;

    for(int i = 1; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] < a[j]) ans += arr[a[i]][j];
        }
    }
    cout << ans << '\n';
}