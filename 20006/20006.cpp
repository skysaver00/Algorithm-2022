#include <iostream>
#include <vector>


using namespace std;
vector < pair<int, string> > player;
vector < pair<int, string> > room[301];

int main() {
    int p, m;
    cin >> p >> m;

    int now = -1;
    for(int i = 0; i < p; i++) {
        int level;
        string name;
        cin >> level >> name;

        if(now == -1) {
            room[0].push_back({level, name});
            now++;
        }
        else {
            for(int i = 0; i <= now; i++) {
                if(level < room[i][0].first)
            }
        }
    }

    return 0;
}