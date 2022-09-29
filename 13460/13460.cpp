#include <iostream>
#include <queue>

using namespace std;

queue <pair<int, pair<int, int>>> red;
queue <pair<int, pair<int, int>>> blue;
char arr[12][12];

int x_[4] = {1, 0, -1, 0};
int y_[4] = {0, 1, 0, -1};

int main() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            arr[i][j] = c;
            if(c == 'R') {
                red.push({0, {i, j}});
                arr[i][j] = '.';
            }
            if(c == 'B') {
                blue.push({0, {i, j}});
                arr[i][j] = '.';
            }
        }
    }

    int flag = 0;

    while(!red.empty()) {
        int redx, redy, blux, bluy;
        int ind = red.front().first;
        redx = red.front().second.first;
        redy = red.front().second.second;
        blux = blue.front().second.second;
        bluy = blue.front().second.second;
        red.pop();
        blue.pop();

        int rstop, bstop;
        rstop = bstop = 0;
        for(int i = 0; i < 4; i++) {
            int nredx, nredy, nblux, nbluy;
            nredx = redx;
            nredy = redy;
            nblux = blux;
            nbluy = bluy;
            while(rstop == 0 || bstop == 0) {
                nredx += x_[i];
                nredy += y_[i];
                nblux += x_[i];
                nbluy += y_[i];

                
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << arr[i][j] << ' ';
        }cout << '\n';
    }

    return 0;
}