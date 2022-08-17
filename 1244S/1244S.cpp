//SAMSUNG
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int arr[6];
int copi[6];

int main() {
	int n;
	int sw;
	string str;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> str >> sw;
		int len = str.length();
		for(int j = 0; j < len; j++) {
            arr[j] = str[j] - 0x30;
            copi[j] = arr[j];
        }
        sort(copi, copi + len, greater<>());
		
		int now = 0;
        int firstans = 0;
		for(int j = 0; j < sw; j++) {
			int max = arr[now];
			int maxloc = now;
            int flag = 0;
            for(int k = 0; k < len; k++) {
                if(copi[k] == arr[k]) flag = 1;
                else {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1) {
                firstans = j;
                break;
            }

			for(int k = now + 1; k < len; k++) {
				if(max < arr[k]) {
					max = arr[k];
					maxloc = k;
				}
			}
			if(maxloc != -1) {
                swap(arr[now], arr[maxloc]);
                now++;
            }
            else {
                j--;
            }
		}
        cout << firstans << "\n";
        for(int j = 0; j < len; j++) cout << arr[j] << ' ';
        cout << "\n";
	}
}