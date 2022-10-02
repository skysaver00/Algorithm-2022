
#include <iostream>

using namespace std;
int s, g, p, d;
int price[40];

int main() {
    int n;
    cin >> n;
    cin >> s >> g >> p >> d;

    string str;
    cin >> str;

    int len = str.length();
    for(int i = 0; i < len; i++) {
        char val = str[i];
        if(val == 'B') {
            price[i + 1] = (s - 1) - price[i];
        } else if(val == 'S') {
            price[i + 1] = (g - 1) - price[i];
        } else if(val == 'G') {
            price[i + 1] = (p - 1) - price[i];
        } else if(val == 'P') {
            price[i + 1] = (d - 1) - price[i];
        } else {
            price[i + 1] = d;
        }
    }
    int ans = 0;
    for(int i = 1; i <= len; i++) ans += price[i];
    cout << ans;
    return 0;
}