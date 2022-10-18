#include <iostream>

using namespace std;
double arr[1000003];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        double n;
        cin >> n;
        arr[i] = arr[i - 1] + n;
    }

    for(int i = 0; i < k; i++) {
        int start, end;
        cin >> start >> end;
        double ans = arr[end] - arr[start - 1];
        ans /= (end - start + 1);
        cout << fixed;
        cout.precision(2);
        cout << ans << '\n';
    }
}