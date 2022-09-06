#include <iostream>

using namespace std;
int n, m;
int r, c, d;
int room[52][52];
int ans = 0;
int Axisx[4] = {-1, 0, 1, 0};
int Axisy[4] = {0, 1, 0, -1};

void startclean(int x, int y, int z) {
    if(room[x][y] == 0) {
        room[x][y] = 2;
        ans++;
    }
    int ne, newx, newy;

    for(int i = 0; i < 4; i++) {
        ne = (z + 3 - i) % 4;
        newx = x + Axisx[ne];
        newy = y + Axisy[ne];
        if(newx < 0 || newy < 0 || newx >= n || newy >= m) continue;
        if(room[newx][newy] == 0) startclean(newx, newy, ne);
    }

    newx = x + Axisx[(z + 2) % 4];
    newy = y + Axisy[(z + 2) % 4];

    if(room[newx][newy] == 1) {
        cout << ans << '\n';
        exit(0);
    }
    startclean(newx, newy, z);
}


int main() {
    cin >> n >> m;
    cin >> r >> c >> d;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> room[i][j];
        }
    }

    startclean(r, c, d);
}