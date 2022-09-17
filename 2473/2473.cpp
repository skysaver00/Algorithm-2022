#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
long long arr[5001];
long long sum;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    long long first, second, third;
    long long fans, sans, tans;
    long long ans = 3100000000;;
    for(int i = 0; i < n; i++) {
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

            if(sum <= 0) {
                second++;
            } else {
                third--;
            }
        }
    }
    cout << fans << ' ' << sans << ' ' << tans <<'\n';
    return 0;
}