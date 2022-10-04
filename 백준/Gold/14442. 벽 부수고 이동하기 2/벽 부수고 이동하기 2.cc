#include <iostream>
#include <queue>

using namespace std;

int n, m, p;
queue <pair<pair<int, int>, int>> que;
int mp[1001][1001];
int val[1001][1001][11];

int x_[4] = {1, 0, -1, 0};
int y_[4] = {0, 1, 0, -1};

void startbfs(int i, int j, int k) {
    que.push({{i, j}, k});
    val[i][j][k] = 1;

    while(!que.empty()) {
        int prex, prey;
        prex = que.front().first.first;
        prey = que.front().first.second;
        int trou = que.front().second;
        que.pop();

        for(int i = 0; i < 4; i++) {
            int newx, newy;
            newx = prex + x_[i];
            newy = prey + y_[i];

            if(newx < 0 || newx >= n || newy < 0 || newy >= m) continue;
            else {
                if(mp[newx][newy] == 0 && val[newx][newy][trou] == 0) {
                    que.push({{newx, newy}, trou});
                    val[newx][newy][trou] = val[prex][prey][trou] + 1;
                }
                
                if(mp[newx][newy] == 1) {
                    if(trou + 1 <= p && val[newx][newy][trou + 1] == 0) {
                        que.push({{newx, newy}, trou + 1});
                        val[newx][newy][trou + 1] = val[prex][prey][trou] + 1;
                    }
                }
            }
        }
    }
    return;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> p;

    string str;
    for(int i = 0; i < n; i++) {
        cin >> str;
        int len = str.length();
        for(int j = 0; j < len; j++) {
            mp[i][j] = str[j] - 0x30;
        }
    }
    
    startbfs(0, 0, 0);

    int ans = -1;
    for(int i = 0; i <= p; i++) {
        if(val[n - 1][m - 1][i] == 0) continue;

        if(ans == -1) ans = val[n - 1][m - 1][i];
        else if(ans > val[n - 1][m - 1][i]) ans = val[n - 1][m - 1][i];
    }

    cout << ans;
    return 0;
}