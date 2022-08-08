#include <iostream>

using namespace std;

int ans[13];

int main() {
    int t;
    cin >> t;

    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 4;
    for(int i = 4; i <= 11; i++) {
        ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
    }

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        cout << ans[n] << "\n";
    }
    return 0;
}