#include <iostream>
#include <queue>

using namespace std;
int arr[51][51];

int gox[4] = {0, 1, 0, -1};
int goy[4] = {-1, 0, 1, 0};

queue <int> que;
queue <int> cp_que;
queue <int> fi_que;

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

        int p = 0;
        int dir = 0;
        while(nowx >= 1 && nowy >= 1 && nowx <= n && nowy <= n) {
            int go = (p / 2) + 1;
            for(int i = 0; i < go; i++) {
                nowx += gox[dir];
                nowy += goy[dir];
                if(arr[nowx][nowy] != 0) que.push(arr[nowx][nowy]);
            }
            dir++;
            p++;
            if(dir == 4) dir = 0;
        }

        int flag = 1;
        while(flag != 0) {
            flag = 0;

            int sz = que.size();
            int bomb = 1;
            for(int i = 0; i < sz; i++) {
                int front = que.front();

                if(i == 0) cp_que.push(front);
                else {
                    int front2 = cp_que.front();
                    if(front == front2) {
                        cp_que.push(front);
                        bomb++;
                    } else {
                        if(bomb >= 4) {
                            while(!cp_que.empty()) {
                                cp_que.pop();
                            }
                            cp_que.push(front);
                            bomb = 1;
                            flag = 1;
                        } else {
                            while(!cp_que.empty()) {
                                int pu_fr = cp_que.front();
                                fi_que.push(pu_fr);
                                cp_que.pop();
                            }
                            bomb = 1;
                            cp_que.push(front);
                        }
                    }
                }

                que.pop();
            }

            if(cp_que.size() >= 4) {
                while(!cp_que.empty()) {
                    cp_que.pop();
                }
            } else {
                while(!cp_que.empty()) {
                    int fr = cp_que.front();
                    cp_que.pop();
                    fi_que.push(fr);
                }
            }

            while(!fi_que.empty()) {
                int fr = fi_que.front();
                fi_que.pop();
                cout << fr << ' ';
                que.push(fr);
            }cout << '\n';
        }



        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) cout << arr[i][j] << ' ';
            cout << '\n';
        }
    }
}