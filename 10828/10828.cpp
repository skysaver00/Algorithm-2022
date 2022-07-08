#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	stack<int> stack;
	int n;
	string str;

	cin >> n;
	while(n--) { 
		int val;	
		cin >> str;
		if(str[1] == 'u') {
			cin >> val;
			stack.push(val);
		}
		else if(str[0] == 'p' && str[1] == 'o') {
			if(stack.empty() == 1) {
				cout << -1 << "\n";
				continue;
			}
			cout << stack.top() << "\n";
			stack.pop();
 		}
		else if(str[0] == 's') {
			cout << stack.size() << "\n";
		}
		else if(str[0] == 'e') {
			cout << stack.empty() << "\n";
		}
		else {
			if(stack.empty() == 1) {
				cout << -1 << "\n";
				continue;
			}
			cout << stack.top() << "\n";
		}
	}

	return 0;
}