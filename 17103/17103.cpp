#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    bool eratos[1000001];
    fill_n(eratos, 1000000, 1);

    eratos[0] = eratos[1] = false;
    for(int i = 2; i <= 1000; i++) {
        for(int j = i * i; j <= 1000000; j += i) {
            eratos[j] = false;
        }
    }

    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;

        int ans = 0;
        for(int j = 2; j <= n / 2; j++) {
            if(eratos[j] == true && eratos[n - j] == true) ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}