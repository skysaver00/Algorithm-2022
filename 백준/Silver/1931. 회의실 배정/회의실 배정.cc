#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <pair<int, int>> vec;
int n;
int st, en;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> st >> en;
        vec.push_back(make_pair(en, st));
    }
    sort(vec.begin(), vec.end());

    int endTime = vec[0].first;
    int ans = 1;
    for(int i = 1; i < n; i++) {
        if(endTime <= vec[i].second) {
            ans++;
            endTime = vec[i].first;
        }
    }
    cout << ans;
}