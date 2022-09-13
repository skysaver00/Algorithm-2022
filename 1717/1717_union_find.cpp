#include <iostream>

using namespace std;
int arr[1000001];

int getParent(int x) {
    if(arr[x] == x) return x;
    return getParent(arr[x]);
}

void unionFind(int x, int y) {
    int a = getParent(x);
    int b = getParent(y);
    if(a < b) arr[b] = a;
    else arr[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) arr[i] = i;

    for(int i = 0; i < m; i++) {
        int o, a, b;
        cin >> o >> a >> b;
        if(o == 0) unionFind(a, b);
        else {
            int x, y;
            x = getParent(a);
            y = getParent(b);
            if(x == y) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}