#include <iostream>
#include <queue>

using namespace std;
int n, m;
int fight[101][101];
bool count[101][101];

queue < pair<int, int> > que;

int x_[4] = {1, 0, -1, 0};
int y_[4] = {0, 1, 0, -1};

int startbfs(int x, int y) {
    if(count[x][y] == 1) return 0;

    int val = 1;
    que.push({x, y});
    count[x][y] = 1;
    int fg = fight[x][y];

    while(!que.empty()) {
        int oldx, oldy;
        oldx = que.front().first;
        oldy = que.front().second;
        que.pop();
        for(int i = 0; i < 4; i++) {
            int newx, newy;
            newx = oldx + x_[i];
            newy = oldy + y_[i];

            if(newx < 0 || newx >= n || newy < 0 || newy >= m) continue;
            if(count[newx][newy] == 1) continue;
            if(fight[newx][newy] != fg) continue;

            val++;
            count[newx][newy] = 1;
            que.push({newx, newy});
        }
    }

    return val;
}

int main() {
    cin >> m >> n;

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < m; j++) {
            if(str[j] == 'W') {
                fight[i][j] = 1;
            } else fight[i][j] = 0;
        }
    }

    int white;
    int black;
    white = black = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int cnt = startbfs(i, j);
            if(fight[i][j] == 1) {
                white += (cnt * cnt);
            } else black += (cnt * cnt);
        }
    }

    cout << white << ' ' << black << '\n';
    return 0;
}