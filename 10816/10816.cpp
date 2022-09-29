#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <pair<int, int>> vec;
int arr[500001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr[i] = num;
    }

    sort(arr, arr + n);

    int now = arr[0];
    int cntnow = 0;
    vec.push_back({now, 1});
    for(int i = 1; i < n; i++) {
        if(now != arr[i]) {
            now = arr[i];
            cntnow++;
            vec.push_back({now, 1});
        } else {
            vec[cntnow].second++;
        }
    }

    int left, mid, right;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int l;
        cin >> l;
        left = 0;
        right = vec.size();
        int target = l;
        int flag = 0;

        while(left <= right) {
            mid = (left + right) / 2;
            if(vec[mid].first < target) {
                left = mid + 1;
            } else if(vec[mid].first > target) {
                right = mid - 1;
            } else {
                flag = 1;
                break;
            }
        }

        if(flag) cout << vec[mid].second << ' ';
        else cout << "0 ";
    }

    return 0;
}