#include <iostream>

using namespace std;
int arr[101];

int find(int x) {
    if(arr[x] == x) return x;
    return arr[x] = find(arr[x]);
}

void merge(int x, int y) {
    int a = find(x);
    int b = find(y);
    if(a < b) arr[b] = a;
    else arr[a] = b;
    return;
}


int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) arr[i] = i;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }

    int val = 0;
    for(int i = 2; i <= n; i++) {
        if(find(i) == 1) val++;
    }
    cout << val << "\n";
}