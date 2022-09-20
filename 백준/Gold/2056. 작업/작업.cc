#include <iostream>
#include <queue>

using namespace std;
vector <int> vec[10001];
priority_queue <int, vector<int>, greater<int>> pq;
int time[10001];
int addtime[10001];
int ind[10001];

int main() {
    ios_base:: sync_with_stdio(0);
    cin.tie();
    cout.tie();

    int n;
    cin >> n;

    int m, l;
    for(int i = 1; i <= n; i++) {
        cin >> m;
        time[i] = m;
        cin >> m;
        for(int j = 0; j < m; j++) {
            cin >> l;
            vec[l].push_back(i);
            ind[i]++;
        }
    }

    for(int i = 1; i <= n; i++) if(ind[i] == 0) pq.push(i);

    while(!pq.empty()) {
        int top = pq.top();
        pq.pop();

        int sz = vec[top].size();
        for(int i = 0; i < sz; i++) {
            ind[vec[top][i]]--;
            if(addtime[vec[top][i]] < time[top]) addtime[vec[top][i]] = time[top];
            if(ind[vec[top][i]] == 0) {
                time[vec[top][i]] += addtime[vec[top][i]];
                pq.push(vec[top][i]);
            }
        }
    }

    int ans = -1;
    for(int i = 1; i <= n; i++) if(time[i] > ans) ans = time[i];
    cout << ans;

    return 0;
}