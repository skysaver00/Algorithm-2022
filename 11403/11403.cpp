#include <iostream>

using namespace std;
int arr[101];

int getParent(int x) {
    if(arr[x] == x) return x;
    return arr[x] = getParent(arr[x]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if(a < b) arr[b] = a;
    else arr[a] = b;
}


int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) arr[i] = i;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int k;
            cin >> k;
            if(k == 1) unionParent(i, j);
        }
    }

    for(int i = )
}