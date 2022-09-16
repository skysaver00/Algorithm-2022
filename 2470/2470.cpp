#include <cstdio>
#include <cmath>

using namespace std;
long long unsort[100001];
long long sort[100001];

void conquer(int left, int right) {
    int i, j, k;
    int mid = (left + right) / 2;

    i = left;
    j = mid + 1;
    k = left;

    while(i <= mid && j <= right) {
        if(unsort[i] < unsort[j]) {

        }
    }
}

void divide() {

}

int main() {

}