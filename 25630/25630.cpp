#include <iostream>

using namespace std;

int main() {
    int l;
    cin >> l;
    string n;
    cin >> n;

    int len = n.length();
    int len2 = len / 2;
    int start1 = 0;
    int start2 = len - len2;

    int ans = 0;
    cout << len2 << '\n';
    for(int i = 0; i < len2; i++) {
        cout << n[start1] << ' ' << n[start2] << '\n';
        if(n[start1] != n[start2]) ans++;
        start1++;
        start2++;
    }

    cout << ans;
    return 0;
}