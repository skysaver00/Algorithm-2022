#include <iostream>
#include <queue>

using namespace std;
int ans[1000001];
bool visited[1000001];

int main() {
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;
    if((S - G) % 2 == 1) {
        if(U % 2 == 0 && D % 2 == 0) {
            cout << "use the stairs";
            return 0;
        }
    }
    if(S > G && D == 0) {
        cout << "use the stairs";
        return 0;
    }
    if(S < G && U == 0) {
        cout << "use the stairs";
        return 0;
    }

    queue <pair<int, int>> que;
    que.push(make_pair(S, 0));
    while(1) {
        int now = que.front().first;
        int time = que.front().second;
        if(now == G) {
            cout << time;
            return 0;
        }
        if(now + U <= F && visited[now + U] == false) {
            visited[now + U] = true;
            que.push(make_pair(now + U, time + 1));
        }
        if(now - D >= 0 && visited[now - D] == false) {
            visited[now - D] = true;
            que.push(make_pair(now - D, time + 1));
        }
        que.pop();
    }
}