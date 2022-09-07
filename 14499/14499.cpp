#include <iostream>

using namespace std;
int dice[4][3];
int room[21][21];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, x, y, k;
    cin >> n >> m >> x >> y >> k;
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
    bool flag = 0;
    bool flag2 = 0;
    for(int i = 0; i < k; i++) {
        int order;
        cin >> order;
        if(order == 1) if(nowy + 1 >= m) continue;
        if(order == 2) if(nowy - 1 < 0) continue;
        if(order == 3) if(nowx - 1 < 0) continue;
        if(order == 4) if(nowx + 1 >= n) continue;

        if(order == 1 || order == 2) {
            if(order == 1) {
                nowy += 1;
                int temp = dice[0][0];
                dice[0][0] = dice[0][1];
                dice[0][1] = dice[0][2];
                dice[0][2] = dice[2][1];
                dice[2][1] = temp;
                if(room[nowx][nowy] != 0) {
                    dice[0][1] = room[nowx][nowy];
                    room[nowx][nowy] = 0;
                } else if(room[nowx][nowy] == 0) {
                    room[nowx][nowy] = dice[0][1];
                }
            } else {
                nowy -= 1;
                int temp = dice[0][0];
                dice[0][0] = dice[2][1];
                dice[2][1] = dice[0][2];
                dice[0][2] = dice[0][1];
                dice[0][1] = temp;
                if(room[nowx][nowy] != 0) {
                    dice[0][1] = room[nowx][nowy];
                    room[nowx][nowy] = 0;
                } else if(room[nowx][nowy] == 0) {
                    room[nowx][nowy] = dice[0][1];
                }
            }
            cout << dice[2][1] << '\n';
        } else if(order == 3 || order == 4) {
            if(order == 3) {
                nowx -= 1;
                int temp = dice[0][1];
                dice[0][1] = dice[1][1];
                dice[1][1] = dice[2][1];
                dice[2][1] = dice[3][1];
                dice[3][1] = temp;
                if(room[nowx][nowy] != 0) {
                    dice[0][1] = room[nowx][nowy];
                    room[nowx][nowy] = 0;
                } else if(room[nowx][nowy] == 0) {
                    room[nowx][nowy] = dice[0][1];
                }
            } else {
                nowx += 1;
                int temp = dice[0][1];
                dice[0][1] = dice[3][1];
                dice[3][1] = dice[2][1];
                dice[2][1] = dice[1][1];
                dice[1][1] = temp;
                if(room[nowx][nowy] != 0) {
                    dice[0][1] = room[nowx][nowy];
                    room[nowx][nowy] = 0;
                } else if(room[nowx][nowy] == 0) {
                    room[nowx][nowy] = dice[0][1];
                }
            }
            cout << dice[2][1] << '\n';
        }
    }
    return 0;
}