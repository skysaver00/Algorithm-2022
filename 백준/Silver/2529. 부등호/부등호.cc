#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int arr[10];
int brr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
char letter[10];
bool cnt[10];
int check;
long long minimum, maximum;
string Cminimum, Cmaximum;


void go(int index, int n, int m) {
    if(index == m) {
        for(int i = 0; i < m - 1; i++) {
            if(letter[i] == '<') {
                if(arr[i] > arr[i + 1]) return;
            } else if(letter[i] == '>') {
                if(arr[i] < arr[i + 1]) return;
            }
        }

        long long val = 0;;
        for(int i = 0; i < m; i++) {
            val += arr[i];
            if(i < m - 1) val *= 10;
        }
        if(minimum > val) minimum = val;
        if(maximum < val) maximum = val;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(cnt[i]) continue;
        cnt[i] = true;
        arr[index] = i;
        go(index + 1, n, m);
        cnt[i] = false;
    }
}

int main() {
    int n;
    cin >> n;
    minimum = 10000000000;
    maximum = -10000000000;
    for(int i = 0; i < n; i++) cin >> letter[i];

    go(0, 10, n + 1);
    int ck = 1;
    for(int i = 0; i < n; i++) ck *= 10;

    if(maximum < ck) cout << '0';
    cout << maximum << "\n";

    if(minimum < ck) cout << '0';
    cout << minimum << "\n";
}
