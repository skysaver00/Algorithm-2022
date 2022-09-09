#include <stdio.h>

int arr[1000001];
int sort[1000001];

void merge(int low, int mid, int high) {
    int i, j, k;
    i = low; j = mid + 1; k = low;

    while(i <= mid && j <= high) {
        if(arr[i] <= arr[j]) {
            sort[k] = arr[i];
            k++; i++;
        } else {
            sort[k] = arr[j];
            k++; j++;
        }
    }

    if(i > mid) {
        for(int l = j; l <= high; l++) {
            sort[k] = arr[l];
            k++;
        }
    } else {
        for(int l = i; l <= mid; l++) {
            sort[k] = arr[l];
            k++;
        }
    }

    for(int l = low; l <= high; l++) arr[l] = sort[l];
    return;
}

void mergesort(int left, int right) {
    int mid = (left + right) / 2;
    if(left < right) {
        mergesort(left, mid);
        mergesort(mid + 1, right);
        merge(left, mid, right);
    }
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    mergesort(0, n - 1);
    for(int i = 0; i < n; i++) printf("%d\n", arr[i]);
}