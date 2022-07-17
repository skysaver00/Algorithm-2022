//O(N)
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;

    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;

        if(val < 2) {
            continue;
        }

        bool flag = false;
        for(int j = 2; j < val - 1; j++) {
            if(val % j == 0) {
                flag = true;
            }
        }

        if(flag == true) {
            continue;
        } else {
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}