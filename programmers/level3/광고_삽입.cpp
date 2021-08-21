#include <string>
#include <vector>
using namespace std;
using ll = long long;
int pt,at;
ll cnt[400000];
int convert(string str){
    int h,m,s;
    sscanf(str.c_str(),"%d:%d:%d",&h,&m,&s);
    return h*3600+m*60+s;
}
string solution(string play_time, string adv_time, vector<string> logs) {

    pt=convert(play_time);
    at=convert(adv_time);

    vector<pair<int,int>> v;
    for(auto s : logs){
        int idx=s.find("-");
        int start=convert(s.substr(0,idx)), end=convert(s.substr(idx+1));
        cnt[start+1]++;
        cnt[end+1]--;
    }
    for(int j=0;j<2;j++)
        for(int i=1;i<=pt;i++) 
            cnt[i]+=cnt[i-1];

    ll mv=0;
    int t=0;
    for(int i=at;i<=pt;i++){
        if(mv<cnt[i]-cnt[i-at]){
            mv = cnt[i]-cnt[i-at];
            t=i-at;
        }
    }
    string rh=to_string(t/3600); 
    string rm=to_string((t%3600)/60);
    string rs=to_string((t%60));
    if(rh.size()<2) rh='0'+rh;
    if(rm.size()<2) rm='0'+rm;
    if(rs.size()<2) rs='0'+rs;
    string ret = rh+":"+rm+":"+rs;
    return ret;
}
