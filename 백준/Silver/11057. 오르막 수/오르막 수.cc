#include <stdio.h>
int arr[1001];
int num[10];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < 10; i++) {
        num[i] = 1;
    }
    arr[1] = 10;

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j < 10; j++) {
            num[j] = num[j] + num[j - 1];
            num[j] %= 10007;
        }

        int sum = 0;
        for(int j = 0; j < 10; j++) {
            sum += num[j];
            sum %= 10007;
        }
        arr[i] = sum;
    }
    printf("%d\n", arr[n]);
    return 0;
}