#include <iostream>

using namespace std;
int arr[1002][1002];
int ans[1002][1002];

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            ans[i][j] = arr[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            ans[i + 1][j + 1] = max(ans[i + 1][j + 1], arr[i + 1][j + 1] + ans[i][j]);
            ans[i + 1][j] = max(ans[i + 1][j], arr[i + 1][j] + ans[i][j]);
            ans[i][j + 1] = max(ans[i][j + 1], arr[i][j + 1] + ans[i][j]);
        }
    }

    cout << ans[n][m] << '\n';
    return 0;
}