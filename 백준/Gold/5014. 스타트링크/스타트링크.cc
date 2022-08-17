#include <iostream>
#include <queue>

using namespace std;
int ans[1000001];
bool visited[1000001];

int main() {
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;

    queue <pair<int, int>> que;
    que.push(make_pair(S, 0));
    while(!que.empty()) {
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
        if(now - D > 0 && visited[now - D] == false) {
            visited[now - D] = true;
            que.push(make_pair(now - D, time + 1));
        }
        que.pop();
    }
    cout << "use the stairs";
}