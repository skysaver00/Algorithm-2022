#include <iostream>

using namespace std;
int ans[10001][3];

int main() {
    ans[1][1] = 1;
    ans[2][2] = 1;
    ans[3][3] = 1;

    int n;
    cin >> n;
    for(int j = 0; j < n; j++) {
        int t;
        cin >> t;
        
        for(int i = 2; i <= t; i++) {
            ans[i][1] = ((ans[i - 1][1] + ans[i - 1][2] + ans[i - 1][3]) % 10000);
            if(i > 2) ans[i][2] = ((ans[i - 2][1] + ans[i - 2][2] + ans[i - 2][3]) % 10000);
            if(i > 3) ans[i][3] = ((ans[i - 3][1] + ans[i - 3][2] + ans[i - 3][3]) % 10000);
        }

        for(int i = 1; i <= t; i++) {
            for(int k = 1; k <= 3; k++) {
                cout << ans[i][k] << ' ';
            }cout << '\n';
        }
    }
    return 0;
}