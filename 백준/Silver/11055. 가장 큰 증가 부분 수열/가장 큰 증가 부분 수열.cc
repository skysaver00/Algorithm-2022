#include <iostream>
using namespace std;

int arr[1001];
int check[1001];

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    check[0] = arr[0];

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j]) {
                if(check[i] <= check[j] + arr[i]) check[i] = check[j] + arr[i];
            }
        }
        if(check[i] == 0) check[i] = arr[i];
    }

    int max = 0;
    for(int i = 0; i < n; i++) {
        if(max < check[i]) max = check[i];
    }
    cout << max << endl;

    return 0;
}