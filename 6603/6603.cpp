#include <iostream>
#include <algorithm>

using namespace std;
int arr[15];
int brr[15];

int main() {
    int n;

    while(1) {
        cin >> n;
        if(n == 0) return 0;
        for(int i = 0; i < n; i++) cin >> arr[i];
        for(int i = 0; i < 6; i++) brr[i] = 0;
        for(int i = 6; i < n; i++) brr[i] = 1;

        do {
            for(int i = 0; i < n; i++) {
                if(brr[i] == 0) cout << arr[i] << ' ';
            }cout << "\n";
        }while(next_permutation(brr, brr + n));
    }
}