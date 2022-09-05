#include <iostream>

using namespace std;
int arr[1000001];

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
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;
    for(int i = 0; i <= a; i++) arr[i] = i;
    for(int i = 0; i < b; i++) {
        int val, n, m;
        cin >> val >> n >> m;

        if(val == 0) {
            unionParent(n, m);
        } else {
            int first = getParent(n);
            int second = getParent(m);
            if(first != second) cout << "NO\n";
            else cout << "YES\n";
        }
    }
    return 0;
}