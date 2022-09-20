#include <iostream>
#include <queue>

using namespace std;
vector <int> vec[10001];
priority_queue <int, vector<int>, greater<int>> pq;
int time[10001];

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
        }
    }
}