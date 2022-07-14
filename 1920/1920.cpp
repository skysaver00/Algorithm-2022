#include <iostream>

#include <algorithm>

using namespace std;

int arr[100001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);

  int m;
  cin >> m;

  for (int i = 0; i < m; i++) {
    int value;
    cin >> value;

    int start = 0;
    int end = n - 1;
    int flag = 0;

    while (end - start >= 0) {
      int mid = (start + end) / 2;
      if (arr[mid] == value) {
        cout << "1\n";
        flag = 1;
        break;
      } else if (arr[mid] <= value) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    if (flag == 0) cout << "0\n";
    flag = 0;
  }

  return 0;
}