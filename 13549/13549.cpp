#include <iostream>
#include <queue>

using namespace std;
bool ans[200001];

int main() {
    int n, k;
    queue <pair<int, int>> que;
    cin >> n >> k;

    ans[n] = 0;
    que.push(make_pair(n, 0));
    while(1) {
        int now = que.front().first;
        int time = que.front().second;

        if(now == k) {
            cout << time;
            return 0;
        }

        if(now >= 0 && now <= 100000) {
            if(ans[now * 2] == false) {
                que.push(make_pair(now * 2, time));
                ans[now * 2] = true;
            }
            if(ans[now - 1] == false) {
                que.push(make_pair(now - 1, time + 1));
                ans[now - 1] = true;
            }
            if(ans[now + 1] == false) {
                que.push(make_pair(now + 1, time + 1));
                ans[now + 1] = true;
            }
        }
        que.pop();
    }
}