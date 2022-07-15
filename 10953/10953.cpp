#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) {
		int a, b;
		cin >> a;
		cin.ignore(10, ',');
		cin >> b;
		cout << a + b << "\n";
	}
	return 0;
}