#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
string straxis[101];
int axis[101][101];
int check[101][101];
queue <pair<int, int>> que;

int addx[4] = {1, 0, -1, 0};
int addy[4] = {0, 1, 0, -1};

void startbfs(int x, int y) {
    check[x][y] = 1;
    que.push(make_pair(x, y));

    int val;
    while(!que.empty()) {
        int topx = que.front().first;
        int topy = que.front().second;
        val = check[topx][topy];
        
        for(int i = 0; i < 4; i++) {
            int newx, newy;
            newx = topx + addx[i];
            newy = topy + addy[i];

            if(newx >= 0 && newx < n && newy >= 0 && newy < m);
            else continue;
            if(check[newx][newy] > 0) continue;
            if(axis[newx][newy] == 0) continue;

            check[newx][newy] = val + 1;
            que.push(make_pair(newx, newy));
        }
        que.pop();
    }
    return;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> straxis[i];
        for(int j = 0; j < m; j++) axis[i][j] = straxis[i][j] - 0x30;
    }

    startbfs(0, 0);
    cout <<  check[n - 1][m - 1];
}