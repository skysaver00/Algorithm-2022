#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int count[1001];
vector <pair<int, int>> vec[1001];
vector <pair<int, pair<int, int>>> pr;

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
    }

    for(int i = 0; i < m; i++) {
        sort(vec[i].begin(), vec[i].end());
    }

    pr.push_back({1, {vec[1][0].second, vec[1][0].first}});
    cout << pr[0].first << ' ' << pr[0].second.first << ' ' << pr[0].second.second << '\n';

    return 0;
}