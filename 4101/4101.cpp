#include <iostream>
using namespace std;
int x, y;

int main() {
    while(1) {
        cin >> x >> y;
        if(x == 0 && y == 0) return 0;
        if(x > y) cout << "Yes\n";
        else cout << "No\n";
    }
}