#include <iostream>
#include <vector>

using namespace std;
int smell[4][4];
vector <int> vec[4][4];
vector < pair<int, pair<int, int> > > fish;
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
    int ans = 0;
    for(int i = 0; i < 3; i++) {
        newsx += sharkx_[sharkmove[i]];
        newsy += sharky_[sharkmove[i]];

        if(newsx < 0 || newsx >= 4 || newsy < 0 || newsy >= 4) return;
        ans += vec[newsx][newsy].size();
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


    for(int i = 0; i < s; i++) {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                int msz = vec[i][j].size();
                for(int k = 0; k < msz; k++) {
                    fish.push_back({i, {j, vec[i][j][k]}});
                }
            }
        }
        killedfish = -9999;
        sharkdfs();
    }



    return 0;
}