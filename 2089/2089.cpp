#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    if(n == 0) {
        cout << 0;
        return 0;
    }

    int arr[33];
    bool flag;

    int now = 0;
    while(n != 0) {
        int k = n % -2;

        if(k == -1) {
            n -= 1;
            k *= -1;
        }
        n /= -2;
        arr[now++] = k;
    }

    for(int i = now - 1; i >= 0; i--) cout << arr[i];

    return 0;
}