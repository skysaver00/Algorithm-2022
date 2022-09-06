#include <iostream>

using namespace std;
int arr[100001];

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int val;
    cin >> val;
    arr[1] = val;
    for(int i = 2; i <= n; i++) {
        int t;
        cin >> t;
        arr[i] = arr[i - 1] + t;
    }

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << arr[b] - arr[a - 1] << '\n';
    }
}