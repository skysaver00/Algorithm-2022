#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int cnt[1005];
vector <pair<int, int>> vec[1005];
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        vec[a].push_back({c, b});
        vec[b].push_back({c, a});
    }

    cnt[1] = 1;
    int sz = vec[1].size();
    int ans = 0;
    for(int i = 0; i < sz; i++) pq.push({vec[1][i].first, vec[1][i].second});

    while(!pq.empty()) {
        int fr, se;
        fr = pq.top().first;
        se = pq.top().second;

        pq.pop();

        if(cnt[se] == 1) continue;
        cnt[se] = 1;
        ans += fr;

        int sz2 = vec[se].size();
        for(int i = 0; i < sz2; i++) pq.push({vec[se][i].first, vec[se][i].second});
    }

    cout << ans << '\n';
    return 0;
}