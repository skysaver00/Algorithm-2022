#include <iostream>

using namespace std;
long long val;

void getval(int i) {
    long long now = 0;
    long long j = 1;
    long long k = 0;
    while(now <= i) {
        val += (j * 9) - k;
        if(k == 0) k = 10;
        else k *= 10;
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    get
}