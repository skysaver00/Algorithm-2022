#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
vector <pair<int, int>> vec;
queue <pair<int, int>> que;
bool check[101];
int rockx, rocky;

bool startbfs(int hx, int hy) {
    que.push(make_pair(hx, hy));
    int len = vec.size();

    while(!que.empty()) {
        int fx, fy;
        fx = que.front().first;
        fy = que.front().second;
        que.pop();

        int cx = abs(fx - rockx);
        int cy = abs(fy - rocky);
        int csq = cx + cy;

        if(csq <= 1000) {
            while(!que.empty()) que.pop();
            return true;
        }

        for(int i = 0; i < len; i++) {
            if(check[i]) continue;
            int vx = vec[i].first;
            int vy = vec[i].second;

            int dx = abs(fx - vx);
            int dy = abs(fy - vy);
            int dsq = dx + dy;

            if(dsq <= 1000) {
                que.push(make_pair(vx, vy));
                check[i] = true;
            }
        }
    }

    return false;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int homex, homey;
        cin >> homex >> homey;
        for(int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            vec.push_back(make_pair(x, y));
        }
        cin >> rockx >> rocky;

        bool ans = startbfs(homex, homey);
        if(ans) cout << "happy\n";
        else cout << "sad\n";

        fill_n(check, 100, false);
        vec.clear();
    }
}