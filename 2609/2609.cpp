#include <iostream>

using namespace std;

int getgcd(int val1, int val2) {
    if(val1 % val2 == 0) return val2;
    else {
        return getgcd(val2, val1 % val2);
    }

}

int main() {
    int val1, val2;
    cin >> val1 >> val2;

    int gcd, lcm;
    if(val1 < val2) {
        int temp;
        temp = val1;
        val1 = val2;
        val2 = temp;
    }

    gcd = getgcd(val1, val2);
    lcm = val1 * val2 / gcd;

    cout << gcd << " " << lcm << "\n";
    return 0;
}