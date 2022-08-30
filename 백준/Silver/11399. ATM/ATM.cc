#include <stdio.h>

int arr[1002];
int arr2[1002];

void QuickSort(int start, int end) {
    int pivot = arr[start];
    int left = start + 1;
    int right = end;

    while(left <= right) {
        while(arr[left] <= pivot) left++;
        while(arr[right] > pivot) right--;

        if(left <= right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }

    if(start < end) {
        int temp = arr[start];
        arr[start] = arr[right];
        arr[right] = temp;

        QuickSort(start, right - 1);
        QuickSort(right + 1, end);
    }

    return;
}

int main() {
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    QuickSort(0, N - 1);

    int sum = 0;
    int realsum = 0;
    for(int i = 0; i < N; i++) {
        sum += arr[i];
        realsum += sum;
    }

    printf("%d\n", realsum);

    return 0;
}