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

        for(int i = 0; i < 4; i++) {
            int newx, newy;
            newx = que.front().first + addx[i];
            newy = que.front().second + addy[i];

            if(newx < 0 || newx >= n || newy < 0 || newy >= m) continue;

            if(axis[newx][newy] == 0 && check[newx][newy] == 0) {
                que.push(make_pair(newx, newy));
                check[newx][newy] = topv + 1;
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
                check[i][j] = 1;
            }
            if(axis[i][j] == -1) check[i][j] = axis[i][j];
        }
    }
    startbfs();

    int maximum = -1;
    bool flag = false;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(check[i][j] > maximum) maximum = check[i][j];
            if(check[i][j] == 0) {
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    if(flag) cout << -1;
    else cout << maximum - 1;
}