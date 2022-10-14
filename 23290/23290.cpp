#include <iostream>
#include <vector>

using namespace std;
int smell[4][4];
bool ckm[4][4];
int vec[4][4][8];
int cfish[4][4][8];
int mfish[4][4][8];
int x_[10] = {0, -1, -1, -1, 0, 1, 1, 1};
int y_[10] = {-1, -1, 0, 1, 1, 1, 0, -1};

int sx, sy;
int sharkx_[4] = {-1, 0, 1, 0};
int sharky_[4] = {0, -1, 0, 1};
int sharkmove[3];
int finalmove[3];
int killedfish;

void sharkkill() {
    int newsx, newsy;
    newsx = sx;
    newsy = sy;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j< 4; j++) {
            ckm[i][j] = 0;
        }
    }

    int ans = 0;
    for(int i = 0; i < 3; i++) {
        newsx += sharkx_[sharkmove[i]];
        newsy += sharky_[sharkmove[i]];

        if(newsx < 0 || newsx >= 4 || newsy < 0 || newsy >= 4) return;
        if(ckm[newsx][newsy] == 0) {
            for(int j = 0; j < 8; j++) ans += vec[newsx][newsy][j];
        }
        ckm[newsx][newsy] = 1;
    }

    if(killedfish < ans) {
        killedfish = ans;
        
        for(int i = 0; i < 3; i++) {
            finalmove[i] = sharkmove[i];
        }
    }
}

void sharkdfs() {
    for(int i = 0; i < 4; i++) {
        sharkmove[0] = i;
        for(int j = 0; j < 4; j++) {
            sharkmove[1] = j;
            for(int k = 0; k < 4; k++) {
                sharkmove[2] = k;
                sharkkill();
            }
        }
    }
}

int main() {
    int m, s;
    cin >> m >> s;

    for(int i = 0; i < m; i++) {
        int fx, fy, d;
        cin >> fx >> fy >> d;
        vec[fx - 1][fy - 1][d - 1]++;
    }
    cin >> sx >> sy;
    sx -= 1;
    sy -= 1;

    for(int ii = 1; ii <= s; ii++) {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                for(int k = 0; k < 8; k++) {
                    cfish[i][j][k] = vec[i][j][k];
                }
            }
        }

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                for(int k = 0; k < 8; k++) {
                    int newfx, newfy, newdir;
                    int fdir = k;
                    int flag = 0;
                    if(vec[i][j][k] == 0) continue;

                    for(int l = 0; l < 8; l++) {
                        newdir = (8 + k - l) % 8;
                        newfx = i + x_[newdir];
                        newfy = j + y_[newdir];
                        
                        if(newfx < 0 || newfx >= 4 || newfy < 0 || newfy >= 4) continue;
                        if(smell[newfx][newfy] != 0 && ii - smell[newfx][newfy] <= 2) continue;
                        if(newfx == sx && newfy == sy) continue;

                        flag = 1;
                        break;
                    }

                    if(flag == 1) mfish[newfx][newfy][newdir] += vec[i][j][k];
                    else mfish[i][j][k] += vec[i][j][k];

                    vec[i][j][k] = 0;
                }
            }
        }

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                for(int k = 0; k < 8; k++) vec[i][j][k] = mfish[i][j][k];
            }
        }
        
        killedfish = -9999;
        sharkdfs();
        for(int i = 0; i < 3; i++) {
            sx += sharkx_[finalmove[i]];
            sy += sharky_[finalmove[i]];

            int pppp = 0;
            for(int k = 0; k < 8; k++) pppp += vec[sx][sy][k];


            if(pppp > 0) {
                smell[sx][sy] = ii;
                for(int k = 0; k < 8; k++) vec[sx][sy][k] = 0;
            }
        }

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                for(int k = 0; k < 8; k++) vec[i][j][k] += cfish[i][j][k];
            }
        }
        
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                for(int k = 0; k < 8; k++) {
                    cfish[i][j][k] = 0;
                    mfish[i][j][k] = 0;
                }
            }
        }
    }

    int finalanswer = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < 8; k++) {
                finalanswer += vec[i][j][k];
            }
        }
    }
    
    cout << finalanswer << '\n';
    return 0;
}