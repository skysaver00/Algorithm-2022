#include <iostream>

using namespace std;
int arr[100001];
int yes[100001];
int no[100001];

int main() {
    double c;
    cin >> c;
    c /= 0.99;

    int n;
    cin >> n;
    int now = 0;
    int day = 0;
    int yon = 1;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] == 0) {
            if(yon == 1) {
                yes[now] = day;
                day = 1;
            } 
            yon = 0;
        } else {
            if(yon == 0) {
                now++;
                no[now] = day;
            }
            yon = 1;
        }
    }
}