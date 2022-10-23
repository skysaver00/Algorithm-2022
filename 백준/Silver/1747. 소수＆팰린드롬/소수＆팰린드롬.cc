#include <iostream>
#include <string>

using namespace std;
int arr[4000005];
int palin[4000005];

int main() {
    arr[0] = arr[1] = 1;
    for(int i = 2; i <= 2000; i++) {
        for(int j = i * i; j <= 4000000; j += i) {
            arr[j] = 1;
        }
    }

    for(int i = 2; i <= 4000000; i++) {
        if(arr[i] == 0) {
            auto str = to_string(i);
            int len = str.length();
            int palinyes = 1;
            for(int i = 0; i < len / 2; i++) {
                if(str[i] != str[len - i - 1]) {
                    palinyes = 0;
                    break;
                }
            }

            if(palinyes) palin[i] = 1;
        }
    }

    int n;
    cin >> n;
    n--;
    while(n++) {
        if(palin[n] == 1) {
            cout << n << '\n';
            return 0;
        }
    }
    cout << "2\n";
}