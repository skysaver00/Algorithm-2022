#include <iostream>
using namespace std;
int ans[1026][1026];
int val[1026][1026];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> ans[i][j];
		}
	}
	
	val[1][1] = ans[1][1];
	for(int i = 2; i <= n; i++) {
		val[1][i] = val[1][i - 1] + ans[1][i];
	}
	
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			val[i][j] = val[i - 1][j] + ans[i][j];
			if(j > 0) val[i][j] += val[i][j - 1];
			if(j > 0) val[i][j] -= val[i - 1][j - 1];
		}
	}
	
	for(int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << val[x2][y2] - val[x2][y1 - 1] - val[x1 - 1][y2] + val[x1 - 1][y1 - 1] << "\n";
	}
	
	return 0;
}