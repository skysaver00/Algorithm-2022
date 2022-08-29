#include <iostream>
#include <queue>

using namespace std;

int n, m;
int axis[1001][1001];
int check[1001][1001];
queue <pair<int, int>> que;
queue <int> val;

int addx[4] = {1, 0, -1, 0};
int addy[4] = {0, 1, 0, -1};

void startbfs() {
    while(!que.empty()) {
        int topx = que.front().first;
        int topy = que.front().second;
        int topv = val.front();
        cout << topx << ' ' << topy << ' ' << topv << '\n';

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) cout << check[i][j] << ' ';
            cout << '\n';
        }

        if(check[topx][topy] == 0) check[topx][topy] = topv;
        for(int i = 0; i < 4; i++) {
            int newx, newy;
            newx = que.front().first + addx[i];
            newy = que.front().second + addy[i];

            if(newx < 0 || newx >= n || newy < 0 || newy >= m) continue;

            if(axis[newx][newy] == 0 && check[newx][newy] == 0) {
                que.push(make_pair(newx, newy));
                val.push(topv + 1);
            }
        }
        que.pop();
        val.pop();
    }
}

int main() {
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> axis[i][j];
            if(axis[i][j] == 1) {
                que.push(make_pair(i, j));
                val.push(1);
            }
            if(axis[i][j] == -1) check[i][j] = axis[i][j];
        }
    }
    startbfs();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cout << check[i][j] << ' ';
        cout << '\n';
    }
}