#include <iostream>
#include <cmath>

using namespace std;
long long arr[100001];
long long val = abs(2100000000);
long long sum;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    int left, right;
    left = 0; right = n - 1;
    int lans, rans;
    while(left != right) {
        sum = abs(arr[left] + arr[right]);
        if(sum <= val) {
            val = sum;
            lans = arr[left];
            rans = arr[right];
        }
        if(arr[left] + arr[right] <= 0) left++;
        else right--;
    }

    cout << lans << ' ' << rans << '\n';
}