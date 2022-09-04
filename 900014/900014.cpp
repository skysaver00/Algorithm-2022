#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n;
vector <pair<int, int>> vec[200001];
queue <int> que;
bool check[200001];
long long val[200001];

long long startbfs(int start) {
    que.push(start);
    check[start] = true;

    while(!que.empty()) {
        int front = que.front();
        que.pop();

        for(int i = 0; i < vec[front].size(); i++) {
            if(check[vec[front][i].first]) continue;
            check[vec[front][i].first] = true;
            val[vec[front][i].first] = val[front] + vec[front][i].second;
            que.push(vec[front][i].first);
        }
    }

    long long ans = 0;
    for(int i = 1; i <= n; i++) ans += val[i];
    return ans;
}

int main() {
    cin >> n;
    for(int i = 1; i < n; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        vec[x].push_back(make_pair(y, t));
        vec[y].push_back(make_pair(x, t));
    }

    for(int i = 1; i <= n; i++) {
        long long ans = startbfs(i);
        cout << ans << '\n';
        fill_n(check, 200001, false);
        fill_n(val, 200001, 0);
    }
}