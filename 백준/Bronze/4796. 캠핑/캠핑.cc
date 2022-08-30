#include <iostream>

using namespace std;
int l, p, v;

int main() {
    int val = 1;
    while(1) {
        cin >> l >> p >> v;
        if(l == 0 && p == 0 && v == 0) break;
        int dvd = v / p;
        int rem = v - (dvd * p);
        int ans = dvd * l;
        if(rem > l) ans += l;
        else ans += rem;
        cout << "Case " << val << ": " << ans << '\n';
        val++;
    }
}