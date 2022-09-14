#include <stdio.h>

int arr[10001];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int start, end;
    start = end = 0;

    int ans = 0;
    int sum = 0;
    while(end <= n) {
        if (sum > m) {
            sum -= arr[start];
            start++;
        } else if (sum < m) {
            sum += arr[end];
            end++;
        } else {
            ans++;
            sum -= arr[start];
            start++;
        }
    }

    printf("%d\n", ans);
    return 0;
}