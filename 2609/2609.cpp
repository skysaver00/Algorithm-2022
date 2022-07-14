#include <iostream>

using namespace std;

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

    if(val1 % val2 == 0) gcd = val2;
    else {
        
    }
}