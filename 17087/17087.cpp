#include <iostream>

using namespace std;

int getgcd(int i, int j) {
    while(j != 0) {
        int temp = i % j;
        i = j;
        j = temp;
    }

    return i;
}

int main() {
    int n, s;
    cin >> n >> s;

    int arr[100001];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int subarr[100001];
    for(int i = 0; i < n; i++) {
        subarr[i] = arr[i] - s;
        if(subarr[i] < 0) subarr[i] *= -1; 
    }

    subarr[1] = getgcd(subarr[0], subarr[1]);

    for(int i = 2; i < n; i++) subarr[i] = getgcd(subarr[i - 1], subarr[i]);
    cout << subarr[n - 1] << "\n";
    
    return 0;
}