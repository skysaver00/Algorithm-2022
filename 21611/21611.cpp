#include <iostream>
#include <queue>

using namespace std;
int arr[51][51];

int gox[4] = {-1, 0, 1, 0};
int goy[4] = {0, 1, 0, -1};

queue <int> que;

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) cin >> arr[i][j];
    }

    int shx, shy;
    shx = shy = (n / 2) + 1;

    for(int i = 0; i < m; i++) {
        int d, s;
        cin >> d >> s;
        if(d == 1) {
            for(int j = 1; j <= s; j++) {
                if(shx - j >= 0) arr[shx - j][shy] = 0;
            }
        }
        if(d == 2) {
            for(int j = 1; j <= s; j++) {
                if(shx + j <= n) arr[shx + j][shy] = 0;
            }
        }
        if(d == 3) {
            for(int j = 1; j <= s; j++) {
                if(shy - j >= 0) arr[shx][shy - j] = 0;
            }
        }
        if(d == 4) {
            for(int j = 1; j <= s; j++) {
                if(shy + j <= n) arr[shx][shy + j] = 0;
            }
        }

        int nowx, nowy;
        nowx = shx;
        nowy = shy;
        cout << nowx << ' ' << nowy << '\n';

        int p = 0;
        int dir = 0;
        while(nowx >= 1 && nowy >= 1 && nowx <= n && nowy <= n) {
            int go = (p / 2) + 1;
            for(int i = 0; i < go; i++) {
                nowx += gox[dir];
                nowy += goy[dir];
                cout << nowx << ' ' << nowy << '\n';
                cout << arr[nowx][nowy] << '\n';
                if(arr[nowx][nowy] != 0) que.push(arr[nowx][nowy]);
            }
            dir++;
            p++;
            if(dir == 4) dir = 0;
        }

        while(!que.empty()) {
            cout << que.front() << ' ';
            que.pop();
        }cout << '\n';

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) cout << arr[i][j] << ' ';
            cout << '\n';
        }
    }
}