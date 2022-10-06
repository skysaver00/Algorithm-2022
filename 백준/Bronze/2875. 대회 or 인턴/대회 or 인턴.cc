#include <iostream>

using namespace std;
int n, m, k;

int main() {
    cin >> n >> m >> k;
    int ingman, ingwoman;
    ingman = ingwoman = 0;

    int nn = n / 2;
    if(nn > m) {
        ingwoman = n - m * 2;
        n = m * 2;
    } else if(nn < m) {
        ingman = m - n / 2;
        m = n / 2;    
        if(nn > m) {
            ingwoman = n - m * 2;
            n = m * 2;
        }
    }
    
    if(ingman + ingwoman >= k) cout << m;
    else {
        while(ingman + ingwoman < k) {
            ingman += 1;
            ingwoman += 2;
            m--;
        }
        cout << m;
    }
}