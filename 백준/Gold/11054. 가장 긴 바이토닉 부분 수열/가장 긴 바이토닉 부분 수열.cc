#include <stdio.h>
int arr[1005];
int up[1005];
int down[1005];

int max (int i, int j) {
    return i >= j ? i : j;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            if(arr[i] > arr[j]) {
                if(up[i] <= up[j]) {
                    up[i] = up[j] + 1;
                }
            }
        }
    }

    int ma = 0;
    int loc = 0;
    for(int i = n; i >= 1; i--) {
        if(ma != max(up[i], ma) || ma == up[i]) {
            ma = max(up[i], ma);
            loc = i;
        }
    }

    down[loc] = 0;
    for(int i = n; i >= 1; i--) {
        for(int j = n; j >= i + 1; j--) {
            if(arr[i] > arr[j]) {
                if(down[i] <= down[j]) {
                    down[i] = down[j] + 1;
                }
            }
        }
    }

    int real = 0;
    for(int i = 1; i <= n; i++) if(real < up[i] + down[i]) real = up[i] + down[i];
    printf("%d\n", real + 1);

    return 0;
}