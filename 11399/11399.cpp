#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <pair<int, int>> vec;

int main() {
    int n, p;
    for(int i = 1; i <= n; i++) {
        cin >> p;
        vec.push_back(make_pair(p, i));
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i <= n; i++) cout << vec[i].second << ' ';
    cout << '\n';
}