#include <iostream>

#include <stack>

#include <queue>

using namespace std;

int main() {
  int n;
  cin >> n;

  int arr[100001];
  for (int i = 0; i < n; i++) cin >> arr[i];

  stack < int > stack;
  queue < char > answer;
  int val = 1;
  int now = 0;

  while (1) {
    if (val < arr[now]) {
      stack.push(val);
      answer.push('+');
      val++;
    } else if (val == arr[now]) {
      if (stack.top() != arr[now]) {
        stack.push(val);
        answer.push('+');
        val++;
      }
      stack.pop();
      answer.push('-');
      val--;
      now++;
    }
  }

  return 0;
}