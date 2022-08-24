#include <iostream>
#include <string>

using namespace std;
int s;

int main() {
    int m, n;
    cin >> m;
    for(int i = 0; i < m; i++) {
        string str;
        cin >> str;
        if(str.compare("add") == 0) {
            cin >> n; n--;
            s = s | (1 << n);
        } else if(str.compare("remove") == 0) {
            cin >> n; n--;
            s = s & ~(1 << n);
        } else if(str.compare("check") == 0) {
            cin >> n; n--;
            if(s & (1 << n) == 1) cout << "1\n";
            else cout << "0\n";
        } else if(str.compare("toggle") == 0) {
            cin >> n; n--;
            s = s ^ (1 << n);
        } else if(str.compare("all") == 0) {
            s = (1 << n) - 1;
        } else {
            s = 0;
        }
    }
}