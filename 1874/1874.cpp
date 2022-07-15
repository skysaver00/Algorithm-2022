#include <iostream>

#include <stack>

#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  int arr[100001];
  for (int i = 0; i < n; i++) cin >> arr[i];

  stack < int > stack;
  vector < char > vec;
  int now = 0;

  for (int i = 1; i <= n; i++) {
    stack.push(i);
    vec.push_back('+');

    while (!stack.empty() && stack.top() == arr[now]) {
      stack.pop();
      vec.push_back('-');
      now++;
    }
  }

  if (!stack.empty()) cout << "NO\n";
  else
    for (int i = 0; i < vec.size(); i++) cout << vec[i] << "\n";

  return 0;
}