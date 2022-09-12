#include <iostream>

using namespace std;
long long val;

int main() {
    int n, k;
    cin >> n >> k;

    int now = 1;
    int i = 1;
    while(val <= k && now < n) {
        if(val + i * 9 <= k) {
            val += (i * 9);
            
        }
    }
}