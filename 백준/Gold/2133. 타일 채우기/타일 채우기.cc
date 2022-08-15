#include <iostream>
using namespace std;
int arr[31];

int main() {
    int n; cin >> n;
    if(n % 2 == 1) {
        cout << 0 << "\n";
        return 0;
    }

    arr[0] = 1;
    arr[1] = 3;
    int n_2 = n / 2;
    for(int i = 2; i <= n_2; i++)
        arr[i] = 4 * arr[i - 1] - arr[i - 2];
    cout << arr[n_2] << "\n";
    return 0;
}