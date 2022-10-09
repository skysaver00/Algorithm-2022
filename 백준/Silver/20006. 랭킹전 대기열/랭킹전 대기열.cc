#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector < pair<string, int> > room[301];

int main() {
    int p, m;
    cin >> p >> m;

    int now = -1;
    for(int i = 0; i < p; i++) {
        int level;
        string name;
        cin >> level >> name;

        if(now == -1) {
            room[0].push_back({name, level});
            now++;
        }
        else {
            bool flag = false;
            for(int i = 0; i <= now; i++) {
                if(level <= room[i][0].second + 10 && level >= room[i][0].second - 10 && room[i].size() < m) {
                    room[i].push_back({name, level});
                    flag = true;
                    break;
                }
            }

            if(!flag) {
                room[now + 1].push_back({name, level});
                now++;
            }
        }
    }

    for(int i = 0; i <= now; i++) {
        sort(room[i].begin(), room[i].end());
    }

    for(int i = 0; i <= now; i++) {
        int sz = room[i].size();
        if(sz == 0) {}
        else if(sz < m) cout << "Waiting!\n";
        else cout << "Started!\n";

        for(int j = 0; j < sz; j++) {
            cout << room[i][j].second << ' ' << room[i][j].first << '\n';
        }
    }

    return 0;
}