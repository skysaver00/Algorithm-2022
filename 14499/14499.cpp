#include <iostream>

using namespace std;
int dice[3][4];
int room[21][21];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, x, y, k;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> room[i][j];
        }
    }
    int nowx, nowy;
    nowx = x;
    nowy = y;
    int up, down;
    up = 0, down = 2;
    int l, r;
    l = 0, r = 2;
    bool flag = 0;
    bool flag2 = 0;
    for(int i = 0; i < k; i++) {
        int order;
        cin >> order;
        if(order == 3 || order == 4) {
            if(order == 4) {
                if(nowx + 1 >= n) continue;
                up = (up + 1) % 4;
                down = (down + 1) % 4;
                nowx += 1;
                dice[1][down] += room[nowx][nowy];
                cout << dice[1][up] << '\n';
            } else if(order == 3) {
                if(nowx - 1 < 0) continue;
                up = (up - 1) % 4;
                down = (down - 1) % 4;
                nowx -= 1;
                dice[1][down] += room[nowx][nowy];
                cout << dice[1][up] << '\n';
            }
        } else if(order == 1 || order == 2) {
            if(order == 1) if(nowy + 1 >= m) continue;
            if(order == 2) if(nowy - 1 < 0) continue;
            if(order == 1) {
                l = (l + 1) % 4;
                r = (r + 1) % 4;
                nowy += 1;
                if(r % 2 == 1) {
                    if(r == 3) {
                        dice[0][2] += room[nowx][nowy];
                        cout << dice[0][0] << '\n';
                    } else if(r == 1) {
                        dice[0][0] += room[nowx][nowy];
                        cout << dice[0][2] << '\n';
                    }
                } else {
                    if(r == 2) {
                        dice[1][up] += room[nowx][nowy];
                        cout << dice[1][down] << '\n';
                    }
                    if(r == 0) {
                        dice[1][down] += room[nowx][nowy];
                        cout << dice[1][up] << '\n';
                    }
                }
            }
            if(order == 2) {
                l = (l - 1) % 4;
                r = (r - 1) % 4;
                nowy -= 1;
                if(r % 2 == 1) {
                    if(r == 3) {
                        dice[0][2] += room[nowx][nowy];
                        cout << dice[0][0] << '\n';
                    } else if(r == 1) {
                        dice[0][0] += room[nowx][nowy];
                        cout << dice[0][2] << '\n';
                    }
                } else {
                    if(r == 2) {
                        dice[1][up] += room[nowx][nowy];
                        cout << dice[1][down] << '\n';
                    }
                    if(r == 0) {
                        dice[1][down] += room[nowx][nowy];
                        cout << dice[1][up] << '\n';
                    }
                }
            }
        }
        for(int a = 0; a < 3; a++) {
            for(int b = 0; b < 4; b++) {
                cout << dice[a][b] << ' ';
            }cout << '\n';
        }
    }


    return 0;
}