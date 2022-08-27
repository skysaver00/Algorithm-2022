#include <iostream>
#include <vector>

using namespace std;
int room[10][10];
int watched[10][10];
vector <pair<int, int>> cameraloc[10];
int cameratype[10];
int looktype[10];
int val;

int lookx[4] = {1, 0, -1, 0};
int looky[4] = {0, 1, 0, -1};

int ans = 100;

void inspect(int n, int m, int camera) {
    cout << "inspect " << n << ' ' << camera <<"\n";
    for(int i = 0; i < camera; i++) {
        if(cameratype[i] == 1) {
            int locx, locy;
            cout << cameraloc[i][0].first << "\n";
            locx = cameraloc[i][0].first;
            locy = cameraloc[i][0].second;
            cout << locx << ' ' << locy << "\n";
            while(locx >= 0 && locx < n && locy >= 0 && locy < m) {
                locx += lookx[looktype[i]];
                locy += looky[looktype[i]];
                if(watched[locx][locy] == 0) watched[locx][locy] = -1;
                if(watched[locx][locy] == 6) break;
            }
        } else if(cameratype[i] == 2) {
            int locx, locy;
            locx = cameraloc[i][0].first;
            locy = cameraloc[i][0].second;
            while(locx >= 0 && locx < n && locy >= 0 && locy < m) {
                locx += lookx[looktype[i]];
                locy += looky[looktype[i]];
                if(watched[locx][locy] == 0) watched[locx][locy] = -1;
                if(watched[locx][locy] == 6) break;
            }

            locx = cameraloc[i][0].first;
            locy = cameraloc[i][0].second;
            while(locx >= 0 && locx < n && locy >= 0 && locy < m) {
                locx += lookx[(looktype[i] + 2) % 4];
                locy += looky[(looktype[i] + 2) % 4];
                if(watched[locx][locy] == 0) watched[locx][locy] = -1;
                if(watched[locx][locy] == 6) break;
            }
        } else if(cameratype[i] == 3) {
            int locx, locy;
            locx = cameraloc[i][0].first;
            locy = cameraloc[i][0].second;
            while(locx >= 0 && locx < n && locy >= 0 && locy < m) {
                locx += lookx[looktype[i]];
                locy += looky[looktype[i]];
                if(watched[locx][locy] == 0) watched[locx][locy] = -1;
                if(watched[locx][locy] == 6) break;
            }

            locx = cameraloc[i][0].first;
            locy = cameraloc[i][0].second;
            while(locx >= 0 && locx < n && locy >= 0 && locy < m) {
                locx += lookx[(looktype[i] + 1) % 4];
                locy += looky[(looktype[i] + 1) % 4];
                if(watched[locx][locy] == 0) watched[locx][locy] = -1;
                if(watched[locx][locy] == 6) break;
            }
        } else if(cameratype[i] == 4) {
            int locx, locy;
            locx = cameraloc[i][0].first;
            locy = cameraloc[i][0].second;
            while(locx >= 0 && locx < n && locy >= 0 && locy < m) {
                locx += lookx[looktype[i]];
                locy += looky[looktype[i]];
                if(watched[locx][locy] == 0) watched[locx][locy] = -1;
                if(watched[locx][locy] == 6) break;
            }

            locx = cameraloc[i][0].first;
            locy = cameraloc[i][0].second;
            while(locx >= 0 && locx < n && locy >= 0 && locy < m) {
                locx += lookx[(looktype[i] + 1) % 4];
                locy += looky[(looktype[i] + 1) % 4];
                if(watched[locx][locy] == 0) watched[locx][locy] = -1;
                if(watched[locx][locy] == 6) break;
            }

            locx = cameraloc[i][0].first;
            locy = cameraloc[i][0].second;
            while(locx >= 0 && locx < n && locy >= 0 && locy < m) {
                locx += lookx[(looktype[i] + 2) % 4];
                locy += looky[(looktype[i] + 2) % 4];
                if(watched[locx][locy] == 0) watched[locx][locy] = -1;
                if(watched[locx][locy] == 6) break;
            }
        } else if(cameratype[i] == 5) {
            int locx, locy;
            locx = cameraloc[i][0].first;
            locy = cameraloc[i][0].second;
            while(locx >= 0 && locx < n && locy >= 0 && locy < m) {
                locx += lookx[looktype[i]];
                locy += looky[looktype[i]];
                if(watched[locx][locy] == 0) watched[locx][locy] = -1;
                if(watched[locx][locy] == 6) break;
            }

            locx = cameraloc[i][0].first;
            locy = cameraloc[i][0].second;
            while(locx >= 0 && locx < n && locy >= 0 && locy < m) {
                locx += lookx[(looktype[i] + 1) % 4];
                locy += looky[(looktype[i] + 1) % 4];
                if(watched[locx][locy] == 0) watched[locx][locy] = -1;
                if(watched[locx][locy] == 6) break;
            }

            locx = cameraloc[i][0].first;
            locy = cameraloc[i][0].second;
            while(locx >= 0 && locx < n && locy >= 0 && locy < m) {
                locx += lookx[(looktype[i] + 2) % 4];
                locy += looky[(looktype[i] + 2) % 4];
                if(watched[locx][locy] == 0) watched[locx][locy] = -1;
                if(watched[locx][locy] == 6) break;
            }

            locx = cameraloc[i][0].first;
            locy = cameraloc[i][0].second;
            while(locx >= 0 && locx < n && locy >= 0 && locy < m) {
                locx += lookx[(looktype[i] + 3) % 4];
                locy += looky[(looktype[i] + 3) % 4];
                if(watched[locx][locy] == 0) watched[locx][locy] = -1;
                if(watched[locx][locy] == 6) break;
            }
        }
    }

    int getzero = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) if(watched[i][j] == 0) getzero++;
    }
    if(ans > getzero) {
        ans = getzero;
    }
}

void go(int index, int type, int n, int m, int camera) {
    if(index == camera) {
        val++;
        inspect(n, m, camera);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                watched[i][j] = room[i][j];
            }
        }
        return;
    }

    for(int i = 0; i < 4; i++) {
        looktype[index] = i;
        go(index + 1, type, n, m, camera);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int camera = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> room[i][j];
            watched[i][j] = room[i][j];
            if(room[i][j] != 0 && room[i][j] != 6) {
                cameratype[camera] = room[i][j];
                cameraloc[camera].push_back(make_pair(i, j));
                camera++;
            }
        }
    }
    cout << camera << "\n";

    go(0, 4, n, m, camera);
    cout << val;
}