#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int arr[10][10];
vector <pair<int, int>> vec;
queue <pair<pair<int, int>, int>> que;

int dx[9] = {0, 1, 1, 1, 0, 0, -1, -1, -1};
int dy[9] = {0, 0, 1, -1, 1, -1, 0, 1, -1};

bool startbfs(int i, int j) {
    que.push({{i, j}, 0});

    while(!que.empty()) {
        int px, py, ind;
        px = que.front().first.first;
        py = que.front().first.second;
        ind = que.front().second;

        if(ind == 8) return 1;
        que.pop();

        int sz = vec.size();
        int flag = 0;
        for(int k = 0; k < sz; k++) {
            int wx, wy;
            wx = vec[k].first + ind;
            wy = vec[k].second;

            if(px == wx && py == wy) {
                flag = 1;
                break;
            }
        }

        if(flag) continue;

        for(int k = 0; k < 9; k++) {
            int nx, ny;
            nx = px + dx[k];
            ny = py + dy[k];

            if(nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;
            else {
                int flag2 = 0;
                for(int l = 0; l < sz; l++) {
                    int wx, wy;
                    wx = vec[l].first + ind;
                    wy = vec[l].second;

                    if(nx == wx && ny == wy) {
                        flag2 = 1;
                        break;
                    }
                }
                if(flag2 == 0) que.push({{nx, ny}, ind + 1});
            }
        }
    }

    return 0;
}

int main() {
    string str;
    for(int i = 0; i < 8; i++) {
        cin >> str;
        for(int j = 0; j < 8; j++) {
            if(str[j] == '#') {
                vec.push_back({i, j});
            }
        }
    }

    bool ans = startbfs(7, 0);
    cout << ans;
    return 0;
}