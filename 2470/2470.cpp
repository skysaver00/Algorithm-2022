#include <cstdio>
#include <cmath>

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
    divide(0, n - 1);

}