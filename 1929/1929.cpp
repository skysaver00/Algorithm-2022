#include <iostream>

using namespace std;

bool isPrime[1000001];

int main() {
    int m, n;
    cin >> m >> n;

    for(int i = 2; i <= n; i++) {
        if(isPrime[i]) continue;
        else {
            for(long long j = (long long) i * i; j <= n; j += i) {
                isPrime[j] = true;
            }
        }
    }
    isPrime[1] = true;

    for(int i = m; i <= n; i++) if(!isPrime[i]) cout << i << "\n";
    return 0;
}