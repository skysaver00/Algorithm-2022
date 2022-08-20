#include <iostream>

using namespace std;
int arr[501][501];
int n, m;

int T[4][8] = {
    {0, 0, 0, 1, 0, 2, 1, 1},
    {0, 0, 1, 0, 1, 1, 2, 0},
    {0, 0, 0, 1, 0, 2, -1, 1},
    {0, 0, 1, 0, 1, -1, 2, 0}
};
int O[8] = {0, 0, 0, 1, 1, 0, 1, 1};
int I[2][8] = {
    {0, 0, 0, 1, 0, 2, 0, 3},
    {0, 0, 1, 0, 2, 0, 3, 0}
};
int S1[2][8] = {
    {0, 0, 1, 0, 1, -1, 2, -1},
    {0, 0, 0, 1, 1, 1, 1, 2}
};
int S2[2][8] = {
    {0, 0, 1, 0, 1, 1, 2, 1},
    {0, 0, 0, -1, 1, -1, 1, -2}
};
int L1[4][8] = {
    {0, 0, 0, -1, 1, -1, 2, -1},
    {0, 0, 1, 0, 1, 1, 1, 2},
    {0, 0, 0, 1, -1, 1, -2, 1},
    {0, 0, 0, 1, 0, 2, 1, 2}
};
int L2[4][8] = {
    {0, 0, 0, 1, 1, 1, 2, 1},
    {0, 0, -1, 0, -1, 1, -1, 2},
    {0, 0, 0, -1, -1, -1, -2, -1},
    {0, 0, 0, 1, 0, 2, -1, 2}
};

bool check(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy) {
    if(ax < 0 || bx < 0 || cx < 0 || dx < 0) return false;
    if(ax >= n || bx >= n || cx >= n || dx >= n) return false;
    if(ay < 0 || by < 0 || cy < 0 || dy < 0) return false;
    if(ay >= m || by >= m || cy >= m || dy >= m) return false;
    return true;
}


int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < 4; k++) {
                int ax, ay, bx, by, cx, cy, dx, dy;
                ax = j + T[k][0];
                ay = i + T[k][1];
                bx = j + T[k][2];
                by = i + T[k][3];
                cx = j + T[k][4];
                cy = i + T[k][5];
                dx = j + T[k][6];
                dy = i + T[k][7];
                bool ck = check(ax, ay, bx, by, cx, cy, dx, dy);
                if(!ck) continue;
                if(ck) {
                    int val = arr[ax][ay] + arr[bx][by] + arr[cx][cy] + arr[dx][dy];
                    //cout << val << "\n";
                    if(val > ans) ans = val;
                }
            }
            
            for(int k = 0; k < 1; k++) {
                int ax, ay, bx, by, cx, cy, dx, dy;
                ax = j + O[0];
                ay = i + O[1];
                bx = j + O[2];
                by = i + O[3];
                cx = j + O[4];
                cy = i + O[5];
                dx = j + O[6];
                dy = i + O[7];
                bool ck = check(ax, ay, bx, by, cx, cy, dx, dy);
                if(!ck) continue;
                if(ck) {
                    int val = arr[ax][ay] + arr[bx][by] + arr[cx][cy] + arr[dx][dy];
                    //cout << val << "\n";
                    if(val > ans) ans = val;
                }
            }
            
            for(int k = 0; k < 2; k++) {
                int ax, ay, bx, by, cx, cy, dx, dy;
                ax = j + I[k][0];
                ay = i + I[k][1];
                bx = j + I[k][2];
                by = i + I[k][3];
                cx = j + I[k][4];
                cy = i + I[k][5];
                dx = j + I[k][6];
                dy = i + I[k][7];
                bool ck = check(ax, ay, bx, by, cx, cy, dx, dy);
                if(!ck) continue;
                if(ck) {
                    //cout << ax << ' ' << ay << ' ' << bx << ' ' << by << ' ' << cx << ' ' << cy << ' ' << dx << ' ' << dy << "\n";
                    int val = arr[ax][ay] + arr[bx][by] + arr[cx][cy] + arr[dx][dy];
                    //cout << val << "\n";
                    if(val > ans) ans = val;
                }
            }

            for(int k = 0; k < 2; k++) {
                int ax, ay, bx, by, cx, cy, dx, dy;
                ax = j + S1[k][0];
                ay = i + S1[k][1];
                bx = j + S1[k][2];
                by = i + S1[k][3];
                cx = j + S1[k][4];
                cy = i + S1[k][5];
                dx = j + S1[k][6];
                dy = i + S1[k][7];
                bool ck = check(ax, ay, bx, by, cx, cy, dx, dy);
                if(!ck) continue;
                if(ck) {
                    int val = arr[ax][ay] + arr[bx][by] + arr[cx][cy] + arr[dx][dy];
                    //cout << val << "\n";
                    if(val > ans) ans = val;
                }
            }

            for(int k = 0; k < 2; k++) {
                int ax, ay, bx, by, cx, cy, dx, dy;
                ax = j + S2[k][0];
                ay = i + S2[k][1];
                bx = j + S2[k][2];
                by = i + S2[k][3];
                cx = j + S2[k][4];
                cy = i + S2[k][5];
                dx = j + S2[k][6];
                dy = i + S2[k][7];
                bool ck = check(ax, ay, bx, by, cx, cy, dx, dy);
                if(!ck) continue;
                if(ck) {
                    int val = arr[ax][ay] + arr[bx][by] + arr[cx][cy] + arr[dx][dy];
                    //cout << val << "\n";
                    if(val > ans) ans = val;
                }
            }

            for(int k = 0; k < 4; k++) {
                int ax, ay, bx, by, cx, cy, dx, dy;
                ax = j + L1[k][0];
                ay = i + L1[k][1];
                bx = j + L1[k][2];
                by = i + L1[k][3];
                cx = j + L1[k][4];
                cy = i + L1[k][5];
                dx = j + L1[k][6];
                dy = i + L1[k][7];
                bool ck = check(ax, ay, bx, by, cx, cy, dx, dy);
                if(!ck) continue;
                if(ck) {
                    int val = arr[ax][ay] + arr[bx][by] + arr[cx][cy] + arr[dx][dy];
                    //cout << val << "\n";
                    if(val > ans) ans = val;
                }
            }

            for(int k = 0; k < 4; k++) {
                int ax, ay, bx, by, cx, cy, dx, dy;
                ax = j + L2[k][0];
                ay = i + L2[k][1];
                bx = j + L2[k][2];
                by = i + L2[k][3];
                cx = j + L2[k][4];
                cy = i + L2[k][5];
                dx = j + L2[k][6];
                dy = i + L2[k][7];
                bool ck = check(ax, ay, bx, by, cx, cy, dx, dy);
                if(!ck) continue;
                if(ck) {
                    int val = arr[ax][ay] + arr[bx][by] + arr[cx][cy] + arr[dx][dy];
                    //cout << val << "\n";
                    if(val > ans) ans = val;
                }
            }
        }
    }

    cout << ans << "\n";
}