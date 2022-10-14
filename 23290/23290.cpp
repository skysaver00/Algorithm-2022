#include <iostream>
#include <vector>

using namespace std;
int smell[4][4];
bool ckm[4][4];
vector <int> vec[4][4];
vector < pair<int, pair<int, int> > > cfish;
vector < pair<int, pair<int, int> > > mfish;
int x_[10] = {0, -1, -1, -1, 0, 1, 1, 1};
int y_[10] = {-1, -1, 0, 1, 1, 1, 0, -1};

int sx, sy;
int sharkx_[4] = {-1, 0, 1, 0};
int sharky_[4] = {0, 1, 0, -1};
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
        if(ckm[newsx][newsy] == 0) ans += vec[newsx][newsy].size();
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
        vec[fx - 1][fy - 1].push_back(d - 1);
    }
    cin >> sx >> sy;
    sx -= 1;
    sy -= 1;

    for(int ii = 0; ii < s; ii++) {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                int msz = vec[i][j].size();
                for(int k = 0; k < msz; k++) {
                    cfish.push_back({i, {j, vec[i][j][k]}});
                }
            }
        }

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                int msz = vec[i][j].size();
                for(int k = 0; k < msz; k++) {
                    int newfx, newfy;
                    int fdir = vec[i][j][k];
                    int newdir;
                    int flag = 0;
                    
                    if(flag == 0 && ii == 3) cout << i << ' ' << j << ' ' << fdir << '\n';
                    
                    for(int l = 0; l < 8; l++) {
                        newdir = fdir - l;
                        if(newdir < 0) newdir += 8;
                        newfx = i + x_[newdir];
                        newfy = j + y_[newdir];

                        if(newfx < 0 || newfx >= 4 || newfy < 0 || newfy >= 4) continue;
                        if(smell[newfx][newfy] > 0) continue;
                        if(newfx == sx && newfy == sy) continue;

                        flag = 1;
                        break;
                    }

                    vec[i][j].erase(vec[i][j].begin());
                    if(flag == 1) mfish.push_back({newfx, {newfy, newdir}});
                    else mfish.push_back({i, {j, fdir}});

                    if(flag == 1 && ii == 3) cout << newfx << ' ' << newfy << ' ' << newdir << '\n';
                    if(flag == 0 && ii == 3) cout << i << ' ' << j << ' ' << fdir << '\n';
                }
            }
        }

        int mfsz = mfish.size();
        for(int i = 0; i < mfsz; i++) {
            vec[mfish[i].first][mfish[i].second.first].push_back(mfish[i].second.second);
        }

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                cout << vec[i][j].size() << ' ';
            }cout << '\n';
        }cout << '\n';
        
        killedfish = -9999;
        sharkdfs();
        for(int i = 0; i < 3; i++) {
            sx += sharkx_[finalmove[i]];
            sy += sharky_[finalmove[i]];

            if(vec[sx][sy].size() > 0) smell[sx][sy] = 3;
            vec[sx][sy].clear();
        }

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(smell[i][j] > 0) smell[i][j] -= 1;
            }
        }

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                cout << vec[i][j].size() << ' ';
            }cout << '\n';
        }cout << '\n';

        int csz = cfish.size();
        for(int i = 0; i < csz; i++) {
            vec[cfish[i].first][cfish[i].second.first].push_back(cfish[i].second.second);
        }

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                cout << vec[i][j].size() << ' ';
            }cout << '\n';
        }cout << '\n';
        
        cfish.clear();
        mfish.clear();
    }

    int finalanswer = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            int finalsz = vec[i][j].size();
            finalanswer += finalsz;
        }
    }
    
    cout << finalanswer << '\n';
    return 0;
}