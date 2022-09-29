#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <pair<int, int>> vec;
int arr[500001];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr[i] = num;
    }

    sort(arr, arr + n);
    
    int now = arr[0];
    vec.push_back({now, 0});
    for(int i = 1; i < n; i++) {
        if(now != arr[i]) {
            now = arr[i];
            vec.push_back({now, 0});
        }
    }

    int left, mid, right;
    for(int i = 0; i < n; i++) {
        left = 0;
        right = vec.size();
        int target = arr[i];

        while(left <= right) {
            mid = (left + right) / 2;
            if(vec[mid].first < target) {
                right = mid - 1;
            } else if(vec[mid].first > target) {
                left = mid + 1;
            } else {
                break;
            }
        }

        vec[mid].second++;
    }

    int sz = vec.size();
    for(int i = 0; i < sz; i++) {
        cout << vec[i].first << ' ' << vec[i].second << '\n';
    }

    return 0;
}