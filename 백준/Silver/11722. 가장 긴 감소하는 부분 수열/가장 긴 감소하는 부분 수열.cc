#include <stdio.h>
int arr[1001];
int total[1001];

int max(int i, int j) {
    return i > j ? i : j;
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] < arr[j]) {
                total[i] = max(total[j] + 1, total[i]);
            }
        }
    }

    int big = 0;
    for(int i = 0; i < n; i++) {
        if(big < total[i]) big = total[i];
    }

    printf("%d\n", big + 1);

    return 0;
}