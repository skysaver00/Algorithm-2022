#include <iostream>

using namespace std;
long long arr[1000001];

long long go(int x){
    if(x == 1) return 1;
    else if(x == 2) return 2;
    else if(x == 3) return 4;

    if(arr[x] > 0) return arr[x];
    arr[x] = (go(x - 1) + go(x - 2) + go(x - 3)) % 1000000009;
    return arr[x];
}

int main() {
    int t, n;
    cin >> t;
    go(1000000);
    for(int i = 0; i < t; i++) {
        cin >> n;
        cout << go(n) << '\n';
    }
}