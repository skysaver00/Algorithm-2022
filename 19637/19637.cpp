#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
vector < pair<int, string> > vec;
map <int, string> mp;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        string str;
        int value;
        cin >> str >> value;
        mp.insert({value, str});
    }

    for(auto iter: mp) {
        vec.push_back({iter.first, iter.second});
    }

    sort(vec.begin(), vec.end());

    int sz = vec.size();

    for(int i = 0; i < m; i++) {
        int p;
        cin >> p;

        int left, right;
        left = 0, right = sz - 1;
        int mid;

        while(left <= right) {
            mid = (left + right) / 2;
            //cout << left << ' ' << mid << ' ' << right << '\n';
            //cout << p << ' ' << vec[mid].first << '\n';
            if(p < vec[mid].first) {
                right = mid - 1;
            } else if(p > vec[mid].first) {
                left = mid + 1;
            } else {
                break;
            }
        }
        if(p > vec[mid].first) mid++;
        cout << vec[mid].second << '\n';
    }
}