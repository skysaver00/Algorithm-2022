#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector <int> question[32001];
priority_queue <int, vector<int>, greater<int>> pq;
queue <int> que;
int ind[32001];
bool check[32001];

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie();
    cout.tie();

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        question[a].push_back(b);
        ind[b]++;
    }

    for(int i = 1; i <= n; i++) {
        if(ind[i] == 0) {
            pq.push(i);
            check[i] = true;
        }
    }

    while(!pq.empty()) {
        int top = pq.top();
        cout << top << ' ';
        pq.pop();

        int sz = question[top].size();
        for(int i = 0; i < sz; i++) {
            ind[question[top][i]]--;
            que.push(question[top][i]);

            if(ind[question[top][i]] == 0 && check[question[top][i]] == false) {
                pq.push(question[top][i]);
                check[question[top][i]] = true;
            } 
        }
    }
    return 0;
}