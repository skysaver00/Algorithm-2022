#include <iostream>
#include <stack>

using namespace std;

int main() {
  string ans;
  stack<int> stack;
  int n;
  cin >> n;

  int m = 0;

  while(n--) {
    int x;
    cin >> x;
    if(x > m) {
      while(x > m) {
        stack.push(++m);
        ans += "+";
      } else {
        
      }
    }
  }

  return 0;
}