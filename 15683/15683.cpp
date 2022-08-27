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

void inspect(int n, int camera) {
    cout << "inspect " << n << ' ' << camera <<"\n";
    cout << cameratype[0] << "\n";
    for(int i = 0; i < camera; i++) {
        if(cameratype[i] == 1) {
            int locx, locy;
            locx = cameraloc[i][0].first;
            locy = cameraloc[i][0].second;
            cout << locx << ' ' << locy << "\n";
            while(locx >= 0 && locx < n && locy >= 0 && locy < n) {
                locx += lookx[looktype[i]];
                locy += looky[looktype[i]];
                if(watched[locx][locy] == 0) watched[locx][locy] = -1;
            }
        } else if(cameratype[i] == 2) {
            int locx, locy;
            locx = cameraloc[i][0].first;
            locy = cameraloc[i][0].second;
            while(locx >= 0 && locx < n && locy >= 0 && locy < n) {
                locx += lookx[looktype[i]];
                locy += looky[looktype[i]];
                if(watched[locx][locy] == 0) watched[locx][locy] = -1;
            }

            locx = cameraloc[i][0].first;
            locy = cameraloc[i][0].second;
            while(locx >= 0 && locx < n && locy >= 0 && locy < n) {
                locx += (lookx[looktype[i]] + 2) % 4;
                locy += (looky[looktype[i]] + 2) % 4;
                if(watched[locx][locy] == 0) watched[locx][locy] = -1;
            }
        } else if(cameratype[i] == 3) {
            int locx, locy;
            locx = cameraloc[i][0].first;
            locy = cameraloc[i][0].second;
            while(locx >= 0 && locx < n && locy >= 0 && locy < n) {
                locx += lookx[looktype[i]];
                locy += looky[looktype[i]];
                if(watched[locx][locy] == 0) watched[locx][locy] = -1;
            }

            locx = cameraloc[i][0].first;
            locy = cameraloc[i][0].second;
            while(locx >= 0 && locx < n && locy >= 0 && locy < n) {
                locx += (lookx[looktype[i]] + 1) % 4;
                locy += (looky[looktype[i]] + 1) % 4;
                if(watched[locx][locy] == 0) watched[locx][locy] = -1;
            }
        } else if(cameratype[i] == 4) {
            int locx, locy;
            locx = cameraloc[i][0].first;
            locy = cameraloc[i][0].second;
            while(locx >= 0 && locx < n && locy >= 0 && locy < n) {
                locx += lookx[looktype[i]];
                locy += looky[looktype[i]];
                if(watched[locx][locy] == 0) watched[locx][locy] = -1;
            }

            locx = cameraloc[i][0].first;
            locy = cameraloc[i][0].second;
            while(locx >= 0 && locx < n && locy >= 0 && locy < n) {
                locx += (lookx[looktype[i]] + 1) % 4;
                locy += (looky[looktype[i]] + 1) % 4;
                if(watched[locx][locy] == 0) watched[locx][locy] = -1;
            }

            locx = cameraloc[i][0].first;
            locy = cameraloc[i][0].second;
            while(locx >= 0 && locx < n && locy >= 0 && locy < n) {
                locx += (lookx[looktype[i]] + 2) % 4;
                locy += (looky[looktype[i]] + 2) % 4;
                if(watched[locx][locy] == 0) watched[locx][locy] = -1;
            }
        } else if(cameratype[i] == 5) {
            int locx, locy;
            locx = cameraloc[i][0].first;
            locy = cameraloc[i][0].second;
            while(locx >= 0 && locx < n && locy >= 0 && locy < n) {
                locx += lookx[looktype[i]];
                locy += looky[looktype[i]];
                if(watched[locx][locy] == 0) watched[locx][locy] = -1;
            }

            locx = cameraloc[i][0].first;
            locy = cameraloc[i][0].second;
            while(locx >= 0 && locx < n && locy >= 0 && locy < n) {
                locx += (lookx[looktype[i]] + 1) % 4;
                locy += (looky[looktype[i]] + 1) % 4;
                if(watched[locx][locy] == 0) watched[locx][locy] = -1;
            }

            locx = cameraloc[i][0].first;
            locy = cameraloc[i][0].second;
            while(locx >= 0 && locx < n && locy >= 0 && locy < n) {
                locx += (lookx[looktype[i]] + 2) % 4;
                locy += (looky[looktype[i]] + 2) % 4;
                if(watched[locx][locy] == 0) watched[locx][locy] = -1;
            }

            locx = cameraloc[i][0].first;
            locy = cameraloc[i][0].second;
            while(locx >= 0 && locx < n && locy >= 0 && locy < n) {
                locx += (lookx[looktype[i]] + 3) % 4;
                locy += (looky[looktype[i]] + 3) % 4;
                if(watched[locx][locy] == 0) watched[locx][locy] = -1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << watched[i][j] << ' ';
        }cout << "\n";
    }
}

void go(int index, int n, int m) {
    if(index == m) {
        val++;
        for(int i = 0; i < m; i++) cout << looktype[i] << ' ';
        inspect(n, m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                watched[i][j] = room[i][j];
            }
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; i++) {
        looktype[index] = i;
        go(index + 1, n, m);
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
                cameraloc[i].push_back(make_pair(i, j));
                camera++;
            }
        }
    }
    cout << camera << "\n";

    go(0, 4, camera);
    cout << val;
}