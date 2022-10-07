#include <string>
#include <vector>

using namespace std;
vector < pair<string, int> > vec;

int solution(string s) {
    int len = s.length();
    
    int ans = len;
    for(int i = 1; i < len; i++) {
        int len2 = s.length();
        for(int j = 0; j < len; j += i) {
            string st = s.substr(j, i);
            
            int flag = 0;
            int sz = vec.size();
            if(sz != 0 && vec[sz - 1].first == st) {
                vec[sz - 1].second++;
                flag = 1;
            }
            
            if(flag == 0) vec.push_back({st, 1});
        }
        
        int sz2 = vec.size();
        int now = 0;
        for(int j = 0; j < sz2; j++) {
            if(vec[j].second == 1) {
            } else if(vec[j].second < 10) {
                now += i;
                now++;
                len2 = len2 - vec[j].second * i;
            } else if(vec[j].second < 100) {
                now += i;
                now += 2;
                len2 = len2 - vec[j].second * i;
            } else if(vec[j].second < 1000) {
                now += i;
                now += 3;
                len2 = len2 - vec[j].second * i;
            } else if(vec[j].second < 10000) {
                now += i;
                now += 4;
                len2 = len2 - vec[j].second * i;
            }
        }
        now += len2;
        vec.clear();
        if(ans > now) ans = now;
    }
    return ans;
}