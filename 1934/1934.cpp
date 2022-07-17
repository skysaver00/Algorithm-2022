#include <iostream>

using namespace std;

int getgcd(int val1, int val2) {
    if(val1 % val2 == 0) return val2;
    else {
        return getgcd(val2, val1 % val2);
    }
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;

        if(a < b) {
            int temp = b;
            b = a;
            a = temp;
        }

        int gcd = getgcd(a, b);
        long long lcm = (long long) a * b / gcd;
        cout << lcm << "\n";
    }

    return 0;
}