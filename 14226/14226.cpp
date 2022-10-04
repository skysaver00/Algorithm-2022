#include <iostream>
#include <queue>

using namespace std;
int s;
int ans;
int tim[2005][2005];
queue <pair<pair<int, int>, int>> que;

void startbfs(int i) {
    que.push({{1, 0}, 0});
    tim[1][0] = 0;

    while(!que.empty()) {
        int emo, cop, time;
        emo = que.front().first.first;
        cop = que.front().first.second;
        time = que.front().second;
        que.pop();

        if(emo <= 0) continue;
        if(emo + cop >= 2000) continue;

        que.push({{emo, emo}, time + 1});

        if(tim[emo + cop][cop] == 9999) {
            que.push({{emo + cop, cop}, time + 1});
            tim[emo + cop][cop] = time + 1;
            if(tim[s][cop] != 9999) {
                ans = tim[s][cop];
                break;
            }
        }

        if(tim[emo - 1][cop] == 9999) {
            que.push({{emo - 1, cop}, time + 1});
            tim[emo - 1][cop] = time + 1;
            if(tim[s][cop] != 9999) {
                ans = tim[s][cop];
                break;
            }
        }

    }
}

int main() {
    for(int i = 0; i <= 2000; i++) fill_n(tim[i], 2001, 9999);
    cin >> s;
    startbfs(1);

    cout << ans;
}