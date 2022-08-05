#include <iostream>

using namespace std;

int get5(int n) {
    int t = 0;
    while(n >= 1) {
        t += (n / 5);
        n /= 5;
    }

    return t;
}

int get2(int n) {
    int t = 0;
    while(n >= 1) {
        t += (n / 2);
        n /= 2;
    }

    return t;
}

int main() {
    int n, m;
    cin >> n >> m;

    int minus = n - m;
    int up_5, down1_5, down2_5;
    int up_2, down1_2, down2_2;

    up_5 = get5(n);
    down1_5 = get5(m);
    down2_5 = get5(minus);

    up_2 = get2(n);
    down1_2 = get2(m);
    down2_2 = get2(minus);

    int ans_5 = up_5 - down1_5 - down2_5;
    int ans_2 = up_2 - down1_2 - down2_2;

    if(ans_5 < ans_2) cout << ans_5;
    else cout << ans_2;

    return 0;
}