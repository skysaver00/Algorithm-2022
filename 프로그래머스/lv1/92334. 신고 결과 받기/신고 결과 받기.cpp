#include <string>
#include <vector>
#include <map>

using namespace std;
vector <int> vec[1001];
int ban[1001];
map <string, int> my_map;
map <string, int> my_map2;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int sz_list = id_list.size();
    int sz_report = report.size();
    
    for(int i = 0; i < sz_list; i++) {
        my_map.insert({id_list[i], i});
    }
    
    for(int i = 0; i < sz_report; i++) {
        my_map2.insert({report[i], 0});
    }
    
    vector<string> report2;
    for(auto iter: my_map2) {
        report2.push_back(iter.first);
    }
    sz_report = report2.size();
    
    for(int i = 0; i < sz_report; i++) {
        string str, str2;
        str = str2 = "";
        
        string now = report2[i];
        int len = now.length();
        int next = 0;
        
        for(int j = 0; j < len; j++) {
            if(now[j] == ' ') {
                next = j + 1;
                break;
            } str += now[j];
        }
        
        for(int j = next; j < len; j++) {
            str2 += now[j];
        }
        
        int val, val2;
        
        for(auto iter: my_map) {
            if(iter.first == str) {
                val = iter.second;
                break;
            }
        }
        
        for(auto iter: my_map) {
            if(iter.first == str2) {
                val2 = iter.second;
                break;
            }
        }
        ban[val2]++;
        vec[val].push_back(val2);
    }
    
    vector<int> answer;
    for(int i = 0; i < sz_list; i++) {
        int sz = vec[i].size();
        int ans = 0;
        for(int j = 0; j < sz; j++) {
            if(ban[vec[i][j]] >= k) ans++;
        }
        answer.push_back(ans);
    }
    
    return answer;
}