#include <iostream>

using namespace std;
int m, n, x, y;
bool arr[40002];

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        fill_n(arr, 40001, 0);
        cin >> m >> n >> x >> y;
        int xx, yy;
        int ans;
        bool flag = false;
        bool flag2 = false;
        if(m > n) {
            xx = yy = ans = y;
            flag = false;
        } else {
            xx = yy = ans = x;
            flag = true;
        }

        if(flag == false) {
            while(xx != x) {
                xx = (xx + n) % m;
                if(xx == 0) xx = m;
                if(arr[xx] == false) arr[xx] = true;
                else {
                    flag2 = true;
                    break;
                }
                ans += n;
            }
        } else {
            while(yy != y) {
                yy = (yy + m) % n;
                if(yy == 0) yy = n;
                if(arr[yy] == false) arr[yy] = true;
                else {
                    flag2 = true;
                    break;
                }
                ans += m;
            }
        }
        if(!flag2) cout << ans << "\n";
        else cout << "-1\n";
    }
}