#include <string>
#include <vector>
#include <map>

using namespace std;
map <int, int> reco_ans;
map <int, int> reco_time;
map <int, int> reco_in;

vector<int> solution(vector<int> fees, vector<string> records) {
    int def_tim = fees[0];
    int def_pri = fees[1];
    int add_tim = fees[2];
    int add_pri = fees[3];
    
    int sz = records.size();
    
    vector <int> answer;
    vector <int> answer2;
    for(int i = 0; i < sz; i++) {
        int first, second;
        string str = records[i];
        int a1 = str[0] - 0x30;
        a1 *= 10;
        a1 += str[1] - 0x30;
        
        int a2 = str[3] - 0x30;
        a2 *= 10;
        a2 += str[4] - 0x30;
        
        first = a1 * 60 + a2;
        
        second = str[6] - 0x30;
        second *= 10;
        second += str[7] - 0x30;
        second *= 10;
        second += str[8] - 0x30;
        second *= 10;
        second += str[9] - 0x30;
        
        if(str[11] == 'I') {
            if(reco_time.find(second) != reco_time.end()) reco_time[second] = first;
            else reco_time.insert({second, first});
            
            if(reco_in.find(second) != reco_in.end()) reco_in[second] = 1;
            else reco_in.insert({second, 1});
        } else {
            int arr;
            arr = reco_time[second];
            
            if(reco_ans.find(second) == reco_ans.end()) {
                reco_ans.insert({second, first - arr});
            }
            else reco_ans[second] += (first - arr);
            
            reco_in[second] = 0;
        }
    }
    
    int end = 23 * 60 + 59;
    int arr;
    
    for(auto iter: reco_in) {
        if(iter.second == 1) {
            arr = reco_time[iter.first];
            
            if(reco_ans.find(iter.first) == reco_ans.end()) {
                reco_ans.insert({iter.first, end - arr});
                continue;
            }
            
            reco_ans[iter.first] += (end - arr);
        }
    }
    
    for(auto iter: reco_ans) {
        int ans = def_pri;
        if(iter.second < def_tim) {
            answer.push_back(ans);
            continue;
        }
        if((iter.second - def_tim) % add_tim > 0) ans += ((iter.second - def_tim) / add_tim + 1) * add_pri;
        else ans += ((iter.second - def_tim) / add_tim) * add_pri;
        answer.push_back(ans);
    }
    
    return answer;
}