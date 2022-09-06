#include <iostream>

using namespace std;
int arr[1026][1026];
int brr[1026][1026];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            brr[i][j] = arr[i][j] + brr[i - 1][j] + brr[i][j - 1] - brr[i - 1][j - 1];
        }
    }

    for(int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 -= 1, y1 -= 1;
        int ans = brr[x2][y2] - brr[x1][y2] - brr[x2][y1] + brr[x1][y1];
        cout << ans << '\n';
    }
}