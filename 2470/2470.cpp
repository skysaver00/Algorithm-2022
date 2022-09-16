#include <cstdio>
#include <cmath>

using namespace std;
long long unsort[100001];
long long sort[100001];

void conquer(int left, int right) {
    int i, j, k;
    int mid = (left + right) / 2;
    printf("%d %d\n", left, right);

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
    for(int i = left; i <= right; i++) printf("%d ", sort[i]);
    printf("\n");

    i = left;
    while(i <= right) unsort[i++] = sort[i++];
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

    for(int i = 0; i < n; i++) printf("%d ", unsort[i]);
}