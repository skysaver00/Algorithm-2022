#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
bool visit[1001][1001];

int main() {
    int n;
    queue<tuple<int, int, int>> que;
    cin >> n;

    que.push(make_tuple(1, 0, 0));
    while(1) {
        int distance = get<0>(que.front());
        int clipboard = get<1>(que.front());
        int time = get<2>(que.front());

        if(get<0>(que.front()) == n) {
            cout << get<2>(que.front());
            return 0;
        }

        if(distance > 0 && distance < 2000) {
            if(visit[distance][distance] == false) {
                visit[distance][distance] = true;
                que.push(make_tuple(distance, distance, time + 1));
            }
            if(visit[distance - 1][clipboard] == false) {
                visit[distance - 1][clipboard] == true;
                que.push(make_tuple(distance - 1, clipboard, time + 1));
            }
        }
        if(clipboard > 0 && distance + clipboard < 2000) {
            if(visit[distance + clipboard][clipboard] == false) {
                visit[distance + clipboard][clipboard] == true;
                que.push(make_tuple(distance + clipboard, clipboard, time + 1));
            }
        }
        que.pop();


        cout << get<0>(que.front()) << ' ' << get<1>(que.front()) << ' ' << get<2>(que.front()) << "\n";
        que.push(make_tuple(get<0>(que.front()), get<0>(que.front()), get<2>(que.front()) + 1));
        que.push(make_tuple(get<0>(que.front()) + get<1>(que.front()), get<0>(que.front()), get<2>(que.front()) + 1));
        if(get<0>(que.front()) > 1) que.push(make_tuple(get<0>(que.front()) - 1, get<0>(que.front()), get<2>(que.front()) + 1));

        que.pop();
    }
}