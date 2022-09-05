#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int check[102];
int n, m;
vector < pair < int, int >> ladde;
vector < pair < int, int >> snake;
queue < int > que;

void startbfs(int start) {
    check[start] = 1;
    que.push(start);

    while (!que.empty()) {
        if (check[100] > 0) {
            while (!que.empty()) que.pop();
            return;
        }

        int top = que.front();
        for (int i = 1; i <= 6; i++) {
            int next = top + i;
            if (check[next] > 0) continue;
            check[next] = check[top] + 1;
            bool flag = false;

            for (int i = 0; i < n; i++) {
                int val = ladde[i].first;
                int val2 = ladde[i].second;
                if (val == next) {
                    if (check[val2] > 0) {
                        if (check[val2] > check[next]) {
                            que.push(val2);
                            check[val2] = check[next];
                            flag = true;
                        }
                    } else {
                        que.push(val2);
                        check[val2] = check[next];
                        flag = true;
                    }
                }
            }

            for (int i = 0; i < m; i++) {
                int val = snake[i].first;
                int val2 = snake[i].second;
                if (val == top) {
                    if (check[val2] > 0) {
                        if (check[val2] > check[next]) {
                            que.push(val2);
                            check[val2] = check[next];
                            flag = true;
                        }
                    } else {
                        que.push(val2);
                        check[val2] = check[next];
                        flag = true;
                    }
                }
            }

            if(flag) {}
            else que.push(next);
        }
        que.pop();
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ladde.push_back(make_pair(x, y));
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        snake.push_back(make_pair(u, v));
    }

    startbfs(1);
    cout << check[100] - 1;
    return 0;
}