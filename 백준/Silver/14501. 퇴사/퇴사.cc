#include <iostream>

using namespace std;
int arr[2][30];
int maximum;

void go(int day, int sum, int n) {
    if(day == n) {
        if(maximum < sum) maximum = sum;
        return;
    }

    if(day > n) return;

    go(day + 1, sum, n);
    go(day + arr[day][0], sum + arr[day][1], n);
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> arr[i][j];
        }
    }
    go(0, 0, n);
    cout << maximum;
}