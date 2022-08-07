#include <iostream>

using namespace std;

int ans[1000004];

int getmin(int i, int j) {
    if(i < j) return i;
    else return j;
}

int main() {
    fill_n(ans, 1000001, 1000000);
    int x;
    cin >> x;

    ans[1] = 0;
    ans[2] = 1;

    for(int i = 3; i <= x; i++) {
        if(i % 3 == 0) ans[i] = ans[i / 3] + 1;
        if(i % 2 == 0) {
            int temp = ans[i / 2] + 1;
            ans[i] = getmin(temp, ans[i]);
        }
        ans[i] = getmin(ans[i - 1] + 1, ans[i]);
    }
    cout << ans[x];
    return 0;
}