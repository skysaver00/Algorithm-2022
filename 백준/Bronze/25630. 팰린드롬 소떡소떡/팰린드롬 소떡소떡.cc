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
    int start2 = len - 1;

    int ans = 0;
    for(int i = 0; i < len2; i++) {
        if(n[start1] != n[start2]) ans++;
        start1++;
        start2--;
    }

    cout << ans;
    return 0;
}