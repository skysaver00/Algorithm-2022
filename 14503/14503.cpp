#include <iostream>

using namespace std;
int r, c, d;
int room[52][52];
int ans = 0;
int Axisx[4] = {-1, 0, 1, 0};
int Axisy[4] = {0, -1, 0, 1};
bool flag = false;

int change(int x) {
    x += 1;
    if(x % 4 == 0) x = 0;
    return x;
}

void startclean(int x, int y) {
    if(room[x][y] == 0) {
        room[x][y] = 2;
        ans++;
        cout << ans << '\n';
    }
    int ne, newx, newy;

    while(1) {
        for(int i = 0; i < 4; i++) {
            d = change(d);
            ne = d;
            newx = x + Axisx[ne];
            newy = y + Axisy[ne];
            if(room[newx][newy] == 2 || room[newx][newy] == 1) continue;
            cout << x << ' ' << Axisx[ne] << ' ' << y << ' ' << Axisy[ne] << '\n';

            cout << newx << ' ' << newy << ' ' << room[newx][newy] << '\n';
            if(room[newx][newy] == 0) startclean(newx, newy);
        }

        if(room[x + Axisx[(ne + 2) % 4]][y + Axisy[(ne + 2) % 4]] == 1) {
            flag = true;
            break;
        }

        x = x + Axisx[(ne + 2) % 4];
        y = y + Axisy[(ne + 2) % 4];
    }

    return;
}


int main() {
    int n, m;
    cin >> n >> m;
    cin >> r >> c >> d;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> room[i][j];
        }
    }

    startclean(r, c);
    cout << ans << '\n';
}