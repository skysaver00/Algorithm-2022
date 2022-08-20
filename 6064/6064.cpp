#include <iostream>

using namespace std;
int m, n, x, y;

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> m >> n >> x >> y;
        int xx, yy;
        xx = yy = 1;
        
        if(m % 2 == 0 && n % 2 == 0 && abs(x - y) % 2 == 1) {
            cout << -1 << "\n";
            continue;
        }

        int upcount = m - n;
        int ans = 0;
        while(xx != x) {
            xx++;
            yy++;
            if(xx > m) xx = 1;
            if(yy > n) yy = 1;
            ans++;
        }
        while(yy != y) {
            if(upcount + yy < 1) yy = n + upcount + yy;
            else yy = (upcount + yy) % n;
            ans += m;
        }
        cout << ans << "\n";
    }
}