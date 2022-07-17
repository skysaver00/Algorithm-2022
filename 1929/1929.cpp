#include <iostream>

using namespace std;

bool isPrime[1000001];

int mian() {
    int m, n;
    cin >> m >> n;

    for(int i = 2; i <= n; i++) {
        if(isPrime[i]) continue;
        else {
            for(int j = i * i; j <= n; j += i) {
                isPrime[j] = true;
            }
        }
    }

    for(int i = m; i <= n; i++) if(!isPrime[i]) cout << i << "\n";
    return 0;
}