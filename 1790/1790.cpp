#include <iostream>

using namespace std;
long long val;

void getval(int i) {
    long long now = 10;
    long long j = 1;
    long long k = 1;
    while(now <= i) {
        val += (j * 9) * k;
        j *= 10;
        k++;
        now *= 10;
    }
    now /= 10;
    val += (i - now + 1) * k;
}

int main() {
    int n, k;
    cin >> n >> k;

    int left = 1;
    int right = n;
    int mid;
    while(left < right) {
        mid = (left + right) / 2;
        getval(mid);
        if(val < k) left = mid + 1;
        else right = mid;
        val = 0;
    }
    getval(left);
    cout << left << ' ' << val << '\n';

    cout << val << '\n';
}