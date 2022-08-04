#include <iostream>

using namespace std;

bool prime[1000001];
int value[500000];
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    for(int i = 2; i < 1001; i++) {
        for(int j = i * i; j <= 1000000; j += i) {
            prime[j] = true;
        }
    }
    int qual = 0;
    for(int i = 3; i <= 999997; i++) {
        if(prime[i] == false) {
            value[qual++] = i;
        }
    }

    int n;
    while(cin >> n && n != 0) {
        for(int i = 0; i < qual / 2; i++) {
            if(prime[n - value[i]] == false) {
                cout << n << " = " << value[i] << " + "
                << n - value[i] << "\n";
                break;
            }
        }
    }

    return 0;
}