#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int axis[101][101];
int check[101][101];
queue <pair<int, int>> que;

int addx[4] = {1, 0, -1, 0};
int addy[4] = {0, 1, 0, -1};

int startbfs(int x, int y) {
    if(axis[x][y] == 0) return;
    else {
        check[x][y] = 1;
        que.push(make_pair(x, y));
    }

    int val;
    while(!que.empty()) {
        int topx = que.front().first;
        int topy = que.front().second;
        val = check[topx][topy];
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> axis[i][j];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) startbfs(i, j);
    }
}