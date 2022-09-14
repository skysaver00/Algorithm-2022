#include <iostream>

using namespace std;
int arr[30001];
int sushi[3001];

int main() {
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 0; i < k; i++) sushi[arr[i]]++;
    int left, right;
    left = 0, right = k - 1;

    while(left / n == 0) {
        
    }
}