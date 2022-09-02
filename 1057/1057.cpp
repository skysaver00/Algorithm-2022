#include <iostream>
#include <vector>

using namespace std;
vector <int> vec;
int fir, sec;

int main() {
    int n;
    cin >> n;
    cin >> fir >> sec;
    for(int i = 1; i <= n; i++) vec.push_back(i);

    if(fir > sec) {
        int temp;
        temp = fir;
        fir = sec;
        sec = temp;
    }

    int ans = 1;
    while(1) {
        int len = vec.size();
        for(int i = 0; i < len; i += 2) {
            int k, l;
            k = vec[i];
            l = vec[i + 1];
            cout << k << ' ' << l << '\n';

            if(k == fir && l == sec) {
                cout << ans;
                return 0;
            }
            else if(k == fir || k == sec) {
                vec.erase(vec.begin() + i + 1);
            } else if(l == fir || l == sec) {
                vec.erase(vec.begin() + i);
            } else {
                vec.erase(vec.begin() + i);
            }
        }
        ans++;
        for(int i = 0; i < vec.size(); i++) {
            cout << vec[i] << ' ';
        } cout << '\n';
    }
}