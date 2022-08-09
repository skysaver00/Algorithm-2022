#include <stdio.h>
long long arr[10][101];

int main() {
    for(int i = 1; i <= 9; i++) arr[i][0] = 1;

    long long mod = 1000000000;
    int n;
    scanf("%d", &n);

    for(int tr = 1; tr < n; tr++) {
        for(int i = 0; i <= 9; i++) {
            if(i == 0) {
                arr[i + 1][tr] = arr[i + 1][tr] + (arr[i][tr - 1] % mod);
            } else if(i == 9) {
                arr[i - 1][tr] = arr[i - 1][tr] + (arr[i][tr - 1] % mod);
            } else {
                arr[i + 1][tr] = arr[i + 1][tr] + (arr[i][tr - 1] % mod);
                arr[i - 1][tr] = arr[i - 1][tr] + (arr[i][tr - 1] % mod);
            }
        }
    }

    long long sum = 0;
    for(int i = 0; i <= 9; i++) {
        sum = (sum + arr[i][n - 1]) % 1000000000;
    }

    printf("%lld\n", sum % 1000000000);
}