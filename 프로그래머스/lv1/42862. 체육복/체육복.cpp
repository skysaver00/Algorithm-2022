#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    answer = n - lost.size();
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    int sz, sz2;
    sz = lost.size();
    sz2 = reserve.size();
    
    for(int i = 0; i < sz; i++) {
        int lostguy = lost[i];
        int flag = 0;
        for(int j = 0; j < sz2; j++) {
            if(lostguy == reserve[j]) {
                flag = 1;
                answer++;
                lost[i] = -9999;
                reserve[j] = -9999;
            }
            if(flag == 1) break;
        }
    }
    
    for(int i = 0; i < sz; i++) {
        int lostguy = lost[i];
        if(lostguy == -9999) continue;
        int flag = 0;
        for(int j = 0; j < sz2; j++) {
            if(lostguy + 1 == reserve[j] || lostguy - 1 == reserve[j]) {
                flag = 1;
                answer++;
                reserve[j] = -9999;
                break;
            }
        }
    }
    
    return answer;
}