#include <iostream>
#include <queue>

using namespace std;
int check[301][301];
queue <pair<int, int>> que;

int addx[8] = {1, 2, -1, -2, -1, -2, 1, 2};
int addy[8] = {2, 1, 2, 1, -2, -1, -2, -1};

int l;
int stx, sty;
int enx, eny;

int startbfs(int x, int y) {
    que.push(make_pair(x, y));
    check[x][y] = 1;
    if(x == enx && y == eny) {
        que.pop();
        return 0;
    }
    
    while(!que.empty()) {
        int topx = que.front().first;
        int topy = que.front().second;

        for(int i = 0; i < 8; i++) {
            int newx = topx + addx[i];
            int newy = topy + addy[i];

            if(newx < 0 || newx >= l || newy < 0 || newy >= l) continue;
            if(check[newx][newy] == 0) {
                check[newx][newy] = check[topx][topy] + 1;
                que.push(make_pair(newx, newy));
            }

            if(newx == enx && newy == eny) {
                return check[newx][newy] - 1;
            }
        }
        que.pop();
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> l;
        cin >> stx >> sty;
        cin >> enx >> eny;

        int ans = startbfs(stx, sty);
        cout << ans << '\n';

        for(int i = 0; i < l; i++) {
            for(int j = 0; j < l; j++) check[i][j] = 0;
        }
        while(!que.empty()) que.pop();
    }
}