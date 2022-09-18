#include <iostream>
#include <queue>

using namespace std;
priority_queue <int, vector<int>, greater<int>> pq;
vector <int> vec[32001];
int ind[32001];

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie();
    cout.tie();
    
    int n, m;
    cin >> n >> m;

    int x, y;
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        vec[x].push_back(y);
        ind[y]++;
    }

    for(int i = 1; i <= n; i++) if(ind[i] == 0) pq.push(i);

    while(!pq.empty()) {
        int top = pq.top();
        cout << top << ' ';
        pq.pop();

        int sz = vec[top].size();
        for(int i = 0; i < sz; i++) {
            ind[vec[top][i]]--;
            if(ind[vec[top][i]] == 0) pq.push(vec[top][i]);
        }
    }
    return 0;
}