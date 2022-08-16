#include <iostream>
#include <queue>

using namespace std;
int map[101][101];
int island[101][101];
bool visit[101][101];
int n;

int xval[4] = {1, 0, -1, 0};
int yval[4] = {0, 1, 0, -1};

bool differ(int x, int y, int val) {
    if(map[x][y] == 0) return false;
    if(island[x][y] != 0) return false;

    queue <pair<int, int>> que;
    que.push(make_pair(x, y));
    while(!que.empty()) {
        int x1 = que.front().first;
        int y1 = que.front().second;
        island[x1][y1] = val;
        for(int i = 0; i < 4; i++) {
            int newx = x1 + xval[i];
            int newy = y1 + yval[i];
            if(newx < 0 || newx >= n) continue;
            if(newy < 0 || newy >= n) continue;
            if(map[newx][newy] == 1 && island[newx][newy] == 0) que.push(make_pair(newx, newy));
        }
        que.pop();
    }
    return true;
}

int length(int x, int y) {
    if(map[x][y] == 0) return 99999999;
    int len = 99999999;
    bool flag = false;

    queue <pair<int, pair<int, int>>> que;
    que.push(make_pair(0, make_pair(x, y)));

    while(!que.empty()) {
        if(flag) {
            que.pop();
            continue;
        }
        int x1 = que.front().second.first;
        int y1 = que.front().second.second;

        bool ck = false;
        for(int i = 0; i < 4; i++) {
            int newx = x1 + xval[i];
            int newy = y1 + yval[i];

            if(island[newx][newy] == 0) {
                ck = true;
                break;
            }
        }
        if(!ck) {
            que.pop();
            return 99999999;
        }
        
        for(int i = 0; i < 4; i++) {
            int newx = x1 + xval[i];
            int newy = y1 + yval[i];
            if(newx < 0 || newx >= n) continue;
            if(newy < 0 || newy >= n) continue;

            if(island[x][y] != island[newx][newy] && island[newx][newy] != 0) {
                if(len > que.front().first) {
                    len = que.front().first;
                    flag = true;
                    break;
                }
            }

            if(island[newx][newy] == 0 && visit[newx][newy] == false) {
                visit[newx][newy] = true;
                que.push(make_pair(que.front().first + 1, make_pair(newx, newy)));
            }
        }

        que.pop();
    }
    return len;
}

void reset() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            visit[i][j] = 0;
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    int val = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            bool ck = differ(i, j, val);
            if(ck) val++;
        }
    }

    int mini = 99999999;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int temp = length(i, j);
            if(mini > temp) mini = temp;
            reset();
        }
    }

    cout << mini;
}