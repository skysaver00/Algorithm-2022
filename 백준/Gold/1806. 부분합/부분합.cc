#include <iostream>

using namespace std;
int arr[100005];
int lef, rig;
int value;
int include = 100001;

int main() {
    int n, s;
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> arr[i];

    value = arr[lef];
    if(value >= s) include = rig - lef + 1;

    while(rig <= n) {
        if(value >= s) if(rig - lef + 1 < include) include = rig - lef + 1;
        if(value < s) {
            rig++;
            value += arr[rig];
        } else {
            value -= arr[lef];
            lef++;
        }
    }
    if(include == 100001) cout << 0;
    else cout << include;
}