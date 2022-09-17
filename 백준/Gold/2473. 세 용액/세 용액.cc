#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
long long arr[5001];
long long sum;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    long long first, second, third;
    long long fans, sans, tans;
    long long ans = 3100000000;
    for(int i = 0; i < n - 2; i++) {
        first = i;
        second = i + 1;
        third = n - 1;

        while(second < third) {
            sum = abs(arr[first] + arr[second] + arr[third]);
            if(ans >= sum) {
                ans = sum;
                fans = arr[first];
                sans = arr[second];
                tans = arr[third];
            }

            if(arr[first] + arr[second] + arr[third] <= 0) {
                second++;
            } else {
                third--;
            }
        }
    }
    cout << fans << ' ' << sans << ' ' << tans <<'\n';
    return 0;
}