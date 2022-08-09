#include <iostream>

using namespace std;
int ans[1001];
int arr[1001];

int main() {
    fill_n(ans, 1000, 1);
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int max = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j] && ans[j] + 1 > ans[i]) ans[i] = ans[j] + 1;
        }
        if(ans[i] > max) max = ans[i];
    }
    cout << max << "\n";
}