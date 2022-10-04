#include <iostream>
#include <queue>

using namespace std;

int n, m, k;
queue <pair<pair<int, int>, int>> que;
int mp[1001][1001];
int val[1001][1001];
bool ck[1001][1001];

int x_[4] = {1, 0, -1, 0};
int y_[4] = {0, 1, 0, -1};

void startbfs(int i, int j, int k) {
    que.push({{i, j}, k});
    ck[i][j] = true;
    val[i][j] = 1;

    while(!que.empty()) {
        int prex, prey;
        prex = que.front().first.first;
        prey = que.front().first.second;
        int trou = que.front().second;
        que.pop();
        cout << prex << ' ' << prey << '\n';

        for(int i = 0; i < 4; i++) {
            int newx, newy;
            newx = prex + x_[i];
            newy = prey + y_[i];
            cout << newx << ' ' << newy << '\n';

            if(newx < 0 || newx >= n || newy < 0 || newy >= m) continue;
            else {
                if(ck[newx][newy]) continue;
                ck[newx][newy] = true;

                if(mp[newx][newy] == 1) {
                    if(trou + 1 <= k) {
                        que.push({{newx, newy}, trou + 1});
                        val[newx][newy] = val[prex][prey] + 1;
                    } else {};
                } else {
                    que.push({{newx, newy}, trou});
                    val[newx][newy] = val[prex][prey] + 1;
                }
            }
        }
    }

    return;
}

int main() {
    cin >> n >> m >> k;

    string str;
    for(int i = 0; i < n; i++) {
        cin >> str;
        int len = str.length();
        for(int j = 0; j < len; j++) {
            mp[i][j] = str[j] - 0x30;
        }
    }
    startbfs(0, 0, 0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << val[i][j] << ' ';
        }cout << '\n';
    }

    cout << val[n - 1][m - 1];
    return 0;
}