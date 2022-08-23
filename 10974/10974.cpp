#include <iostream>
#include <algorithm>

using namespace std;
int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};

int main() {
    int n;
    cin >> n;
    int val = 1;
    for(int i = n; i > 0; i--) val *= i;
    for(int i = 0; i < val; i++) {
        for(int j = 0; j < n; j++) cout << arr[j] << ' ';
        cout << '\n';
        next_permutation(arr, arr + n);
    }
}