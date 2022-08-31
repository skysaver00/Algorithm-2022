#include <iostream>

using namespace std;
int n, m;
string strold[51];
string strnew[51];
int old[51][51];
int neww[51][51];

void flip(int x, int y) {
    for(int i = x; i < x + 3; i++) {
        for(int j = y; j < y + 3; j++) {
            old[i][j] = 1 - old[i][j];
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> strold[i];
    for(int i = 0; i < n; i++) cin >> strnew[i];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            old[i][j] = strold[i][j] - 0x30;
            neww[i][j] = strnew[i][j] - 0x30;
        }
    }

    int ans = 0;
    for(int i = 0; i < n - 2; i++) {
        for(int j = 0; j < m - 2; j++) {
            if(old[i][j] != neww[i][j]) {
                ans++;
                flip(i, j);
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(old[i][j] != neww[i][j]) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << ans;
}