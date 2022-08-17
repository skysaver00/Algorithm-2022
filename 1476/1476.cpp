#include <iostream>

using namespace std;

int main() {
    int E, S, M;
    int EE, SS, MM;
    cin >> EE >> SS >> MM;
    E = S = M = 1;

    int ans = 1;
    while(1) {
        if(EE == E && SS == S && MM == M) {
            cout << ans;
            return 0;
        }
        E++; S++; M++;
        if(E % 16 == 0) E = 1;
        if(S % 29 == 0) S = 1;
        if(M % 20 == 0) M = 1;
        ans++;
    }
}