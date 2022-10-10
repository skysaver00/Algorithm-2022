#include <iostream>

using namespace std;
long long ans[10001][3];

int main() {
    ans[1][1] = 1;
    ans[2][2] = 1;
    ans[3][3] = 1;

    int n;
    int maxi = -1;
    cin >> n;
    for(int j = 0; j < n; j++) {
        int t;
        cin >> t;
        
        if(maxi >= t) {
            cout << ans[t][1] + ans[t][2] + ans[t][3] << '\n';
            continue;
        }
        if(maxi < t) maxi = t;
        
        for(int i = 2; i <= t; i++) {
            ans[i][1] = (ans[i - 1][1]);
            if(i > 2) ans[i][2] = (ans[i - 2][1] + ans[i - 2][2]);
            if(i > 3) ans[i][3] = (ans[i - 3][1] + ans[i - 3][2] + ans[i - 3][3]);
        }
        
        cout << ans[t][1] + ans[t][2] + ans[t][3] << '\n';
    }
    return 0;
}