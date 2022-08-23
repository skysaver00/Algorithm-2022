#include <iostream>
#include <algorithm>

using namespace std;
int arr[10001];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    prev_permutation(arr, arr + n);
    
    bool check = false;
    for(int i = 1; i < n; i++) if(arr[i - 1] < arr[i]) check = true;
    if(!check) cout << -1;
    else {
        for(int  i = 0; i < n; i++) cout << arr[i] << ' ';
    }
}