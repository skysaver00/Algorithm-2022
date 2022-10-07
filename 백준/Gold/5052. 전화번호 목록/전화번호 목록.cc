#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
vector <string> vec;
int arr[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fill_n(arr, 10000, 0);

        for(int i = 0; i < n; i++) {
            string st;
            cin >> st;
            vec.push_back(st);
        }

        sort(vec.begin(), vec.end());

        int flag = 0;
        for(int i = 0; i < n - 1; i++) {

            string fir = vec[i];
            int len = fir.length();
            string sec = vec[i + 1].substr(0, len);
            
            if(fir == sec) flag = 1;
            if(flag == 1) {
                break;
            }
        }
        

        if(flag) cout << "NO\n";
        else cout << "YES\n";

        vec.clear();
    }
}