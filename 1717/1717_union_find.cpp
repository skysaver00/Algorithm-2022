#include <iostream>

using namespace std;
int arr[1000001];

int getParent(int x) {
    if(arr[x] == x) return x;
    return arr[x] = getParent(arr[x]);
}

int unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if(a < b) arr[b] = a;
    else arr[a] = b;
}

int main() {
    int val, n, m;
    cin >> val >> n >> m;
    for(int i = 0; i <= n; i++) arr[i] = i;

    

}