#include <iostream>

using namespace std;
int ans[31];

int main() {
    int n;
    cin >> n;
    if(n % 2 == 1) {
        cout << 0;
        return 0;
    }
    ans[0] = 1;
    ans[2] = 3;
    for(int i = 4; i <= n; i += 2) {
        ans[i] = ans[i - 2] * 3;
        int j = i - 2;
        while(j != 0) {
            j -= 2;
            ans[i] += ans[j] * 2;
        }
    }
    cout << ans[n];
}