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

void clean(int x, int y) {
    if(x == 0 && y == 0) {
        ans++;
    }
}

void startclean(int x, int y) {
    if(flag) return;
    if(room[x][y] == 0) clean(x, y);
    int newx, newy;

    while(1) {
        for(int i = 0; i < 4; i++) {
            d = change(d);
            int now = d;
            cout << d << '\n';
            newx = x + Axisx[now];
            newy = y + Axisy[now];
            if(room[newx][newy] == 0) {
                startclean(newx, newy);
            }
        }

    }
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
}