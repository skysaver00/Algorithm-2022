#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    int n;
    queue<tuple<int, int, int>> que;
    cin >> n;

    que.push(make_tuple(1, 0, 0));
    while(1) {
        if(get<0>(que.front()) == n) {
            cout << get<2>(que.front());
            return 0;
        }
        cout << get<0>(que.front()) << ' ' << get<1>(que.front()) << ' ' << get<2>(que.front()) << "\n";
        que.push(make_tuple(get<0>(que.front()), get<0>(que.front()), get<2>(que.front()) + 1));
        que.push(make_tuple(get<0>(que.front()) + get<1>(que.front()), get<0>(que.front()), get<2>(que.front()) + 1));
        if(get<0>(que.front()) > 1) que.push(make_tuple(get<0>(que.front()) - 1, get<0>(que.front()), get<2>(que.front()) + 1));

        que.pop();
    }
}