#include <iostream>
#include <vector>

using namespace std;
int arr[100001];
int yes[100001];
int no[100001];
vector <int> vec;

int main() {
    double c;
    cin >> c;
    c /= 0.99;
    int cc = c;

    int n;
    cin >> n;
    int now = 0;
    int day = 0;
    int yon = 1;
    int maxi = -9999;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(maxi < arr[i]) maxi = arr[i];
        if(arr[i] == 0) {
            if(yon == 1) {
                yes[now] = day;
                day = 1;
            } else if(yon == 0) {
                day++;
            }
            yon = 0;
        } else {
            if(yon == 0) {
                no[now] = day;
                day = 1;
                now++;
            } else {
                day++;
            }
            yon = 1;
        }
    }
    if(yon == 0) no[now] = day;
    else yes[now] = day;

    int la = -9999;
    for(int i = 0; i <= now; i++) {
        int maxday = 0;
        for(int j = i; j <= now; j++) {
            if(cc >= no[j]) {
                maxday += yes[j];
                maxday += no[j];
                cc -= no[j];
            } else {
                maxday += yes[j];
                maxday += cc;
                break;
            }
        }
        if(la < maxday) la = maxday;
        cc = c;
    }

    cout << la << '\n' << maxi << '\n';

    return 0;
}