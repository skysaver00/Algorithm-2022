#include <iostream>
#include <queue>

using namespace std;
int visit[2000][2000];

int main() {
    int n;
    cin >> n;
    queue <pair<int, pair<int, int>>> que;
    que.push(make_pair(1, make_pair(0, 0)));
    while(1) {
        int distance = que.front().first;
        int clipboard = que.front().second.first;
        int time = que.front().second.second;

        if(distance == n) {
            cout << time;
            return 0;
        }

        if(distance > 0 && distance < 2000) {
            if(visit[distance][distance] == false) {
                que.push(make_pair(distance, make_pair(distance, time + 1)));
                visit[distance][distance] = true;
            }
            if(visit[distance - 1][clipboard] == false) {
                que.push(make_pair(distance - 1, make_pair(clipboard, time + 1)));
                visit[distance - 1][clipboard] = true;
            }
        }
        
        if(clipboard > 0 && distance + clipboard < 2000) {
            if(visit[distance + clipboard][clipboard] == false) {
                que.push(make_pair(distance + clipboard, make_pair(clipboard, time + 1)));
                visit[distance + clipboard][clipboard] = true;
            }
        }
        que.pop();
    }
}