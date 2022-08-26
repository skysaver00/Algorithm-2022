#include <iostream>
#include <stack>

using namespace std;
string cmap[26];
int map[26][26];
int check[26][26];
stack <pair<int, int>> stk;
int ans = 0;
int n;
int axisx[4] = {1, 0, -1, 0};
int axisy[4] = {0, 1, 0, -1};

bool go(int x, int y) {
    if(check[x][y]) return false;
    if(map[x][y] == 0) return false;

    ans = 1;
    check[x][y] = true;
    stk.push(make_pair(x, y));
    cout << x << ' ' << y << '\n';

    while(!stk.empty()) {
        int topx, topy;
        topx = stk.top().first;
        topy = stk.top().second;

        bool flag = true;
        for(int i = 0; i < 4; i++) {
            int newx, newy;
            newx = topx + axisx[i];
            newy = topy + axisy[i];
            if(newx < 0 || newx >= n) continue;
            if(newy < 0 || newy >= n) continue;
            if(check[newx][newy]) continue;
            if(map[newx][newy] == 0) continue;
            else {
                cout << newx << ' ' << newy << '\n';
                ans++;
                check[newx][newy] = true;
                stk.push(make_pair(newx, newy));
                flag = false;
                break;
            }
        }

        if(flag) stk.pop();
    }
    return true;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> cmap[i];
        for(int j = 0; j < n; j++) {
            map[i][j] = cmap[i][j] - 0x30;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            bool get = go(i, j);
            if(get) cout << ans << '\n';
        }
    }
}