#include <string>
#include <vector>
using namespace std;
string sol(string str){
    string ret,ans;
    int cnt=0;
    for(auto c : str){
        if(c=='0' && ret.size()>=2 && ret.substr(ret.size()-2,2)=="11"){            
            ret.pop_back();ret.pop_back();
            cnt++;
        } else ret.push_back(c);
    }
    ret='0'+ret;
    int idx;
    for(int i=ret.size()-1;i>=0;i--){
        if(ret[i]=='0') {
            idx=i;
            break;
        }
    }
    for(int i=0;i<=idx;i++) ans+=ret[i]; 
    while(cnt--) ans+="110";
    for(int i=idx+1;i<ret.size();i++) ans+=ret[i];
    return ans.substr(1);
}
vector<string> solution(vector<string> s) {
    vector<string> answer;
    for(auto str : s) answer.push_back(sol(str));
    return answer;
}