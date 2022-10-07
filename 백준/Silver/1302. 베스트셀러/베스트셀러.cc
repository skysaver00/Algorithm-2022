#include <iostream>
#include <map>

using namespace std;
map <string, int> mp;

int main() {
    int n;
    cin >> n;

    while(n--) {
        string str;
        cin >> str;

        if(mp.find(str) == mp.end()) {
            mp.insert({str, 1});
        } else {
            mp[str]++;
        }
    }

    string ans;
    int val = 0;
    for(auto i : mp) {
        if(i.second > val) {
            val = i.second;
            ans = i.first;
        }
    }
    cout << ans << '\n';
    return 0;
}