#include <iostream>
#include <queue>
#include <vector>

using namespace std;
priority_queue <int, vector<int>, greater<int>> pq;
vector <int> vec[501];
int ind[501];
int construction[501];
int taketime[501];

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie();
    cout.tie();

    int n;
    cin >> n;
    
    int pri;
    for(int i = 1; i <= n; i++) {
        cin >> construction[i];
        while(1) {
            cin >> pri;
            if(pri == -1) break;
            else {
                vec[pri].push_back(i);
                ind[i]++;
            } 
        }
    }

    for(int i = 1; i <= n; i++) if(ind[i] == 0) pq.push(i);

    while(!pq.empty()) {
        int top = pq.top();
        construction[top] += taketime[top];
        pq.pop();

        int sz = vec[top].size();
        for(int i = 0; i < sz; i++) {
            ind[vec[top][i]]--;
            if(taketime[vec[top][i]] < construction[top]) taketime[vec[top][i]] = construction[top];
            if(ind[vec[top][i]] == 0) {
                pq.push(vec[top][i]);
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << construction[i] << '\n';
    return 0;
}