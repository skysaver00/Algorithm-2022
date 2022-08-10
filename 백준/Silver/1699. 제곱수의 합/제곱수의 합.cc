#include <iostream>
#include <cmath>
using namespace std;

int arr[100001];

int max(int i, int j) {
    return i > j ? i : j;
}

int main() {
    for(int i = 0; i <= 100000; i++) arr[i] = i;
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j * j <= i; j++) {
            arr[i] = min(arr[i], arr[i - j * j] + 1);
        }
    }

    printf("%d\n", arr[n]);

    return 0;
}