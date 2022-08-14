#include <iostream>

using namespace std;
int up[1001];
int down[1001];
int arr[1001];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    fill_n(up, 1000, 1);
    fill_n(down, 1000, 1);
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i] && up[i] < up[j] + 1) up[i] = up[j] + 1;
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - 1; j > i; j--) {
            if(arr[j] < arr[i] && down[i] < down[j] + 1) down[i] = down[j] + 1;
        }
    }
    int max = 0;
    for(int i = 0; i < n; i++) {
        if(max < up[i] + down[i] - 1) max = up[i] + down[i] - 1;
    }
    cout << max;
}