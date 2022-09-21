#include <iostream>

using namespace std;

int arr[1001][1001];
int ans[1001][1001];

int max(int i, int j) {
    if(i > j) return i;
    else return j;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    ans[0][0] = arr[0][0];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(j > 0) ans[i][j] = max(ans[i][j], ans[i][j - 1] + arr[i][j]);
            if(i > 0) ans[i][j] = max(ans[i][j], ans[i - 1][j] + arr[i][j]);
            if(i > 0 && j > 0) ans[i][j] = max(ans[i][j], ans[i - 1][j - 1] + arr[i][j]);
        }
    }

    cout << ans[n - 1][m - 1];
    return 0;
}