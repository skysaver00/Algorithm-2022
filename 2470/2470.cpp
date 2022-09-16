#include <cstdio>
#include <math.h>

int unsort[100001];
int sort[100001];

void conquer(int left, int right) {
    int i, j, k;
    int mid = (left + right) / 2;

    i = left;
    j = mid + 1;
    k = left;

    while(i <= mid && j <= right) {
        if(unsort[i] < unsort[j]) sort[k++] = unsort[i++];
        else sort[k++] = unsort[j++];
    }

    if(i <= mid) {
        while(i <= mid) sort[k++] = unsort[i++];
    } else if(j <= right) {
        while(j <= right) sort[k++] = unsort[j++];
    }

    i = left;
    while(i <= right) {
        unsort[i] = sort[i];
        i++;
    }
}

void divide(int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        divide(left, mid);
        divide(mid + 1, right);
        conquer(left, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &unsort[i]);
    divide(0, n - 1);

    int left, right;
    left = 0; right = n - 1;
    int val, sum;
    val = 2100000000;
    int lans, rans;

    while(left != right) {
        sum = abs(unsort[left] + unsort[right]);
        
        if(sum <= val) {
            val = sum;
            lans = unsort[left];
            rans = unsort[right];
        }

        if(unsort[left] + unsort[right] < 0) left++;
        else right--;
    }
    printf("%d %d\n", lans, rans);
    return 0;
}