#include <stdio.h>

int arr[505];
int brr[2][505];

void choice(int i, int j) {
    if(brr[(i - 1) % 2][j - 1] >= brr[(i - 1) % 2][j]) {
        brr[i % 2][j] = brr[(i - 1) % 2][j - 1] + arr[j];
    }
    else {
        brr[i % 2][j] = brr[(i - 1) % 2][j] + arr[j];
    }

    return;
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            scanf("%d", &arr[j]);
        }

        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i) {
                if(j == 0) brr[i % 2][j] = brr[(i - 1) % 2][j] + arr[j];
                else brr[i % 2][j] = brr[(i - 1) % 2][j - 1] + arr[j];
            }
            else {
                choice(i, j);
            }
        }
    }

    int max = -99999999;
    int ud = 0;
    if(n % 2 == 1) ud = 0;
    else ud = 1;

    for(int i = 0 ; i < n; i++) {
        if(max <= brr[ud][i]) max = brr[ud][i];
    }

    printf("%d\n", max);

    return 0;
}