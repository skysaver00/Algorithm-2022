#include <iostream>

using namespace std;
int arr[201];
bool arr2[201][201];
int arr3[1001];

int find(int x) {
    if(arr[x] == x) return x;
    return arr[x] = find(arr[x]);
}

void merge(int x, int y) {
    int a = find(x);
    int b = find(y);
    if(a > b) arr[a] = b;
    else arr[b] = a;

    return;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) arr[i] = i;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> arr2[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(arr2[i][j]) merge(i, j);
        }
    }

    for(int i = 0; i < m; i++) cin >> arr3[i];
    for(int i = 1; i < m; i++) {
        int a, b;
        a = arr3[i - 1];
        b = arr3[i];
        if(find(a) != find(b)) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}