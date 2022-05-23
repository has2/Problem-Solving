#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
int t[10000];
vector<int> fees;
map<int,int> pay;
vector<string> split(string s){
    vector<string> ret;
    int idx;
    s+=' ';
    while((idx = s.find(' '))!=string::npos){
        ret.push_back(s.substr(0,idx));
        printf("%s ",s.substr(0,idx).c_str());
        s = s.substr(idx+1);
    }
    return ret;
}
vector<int> solution(vector<int> _fees, vector<string> records) {
    vector<int> answer;
    fees=_fees;
    memset(t,-1,sizeof(t));
    for(auto r : records){
        auto ret = split(r);
        int h,m,num=stoi(ret[1]);
        sscanf(ret[0].c_str(),"%d:%d",&h,&m);
        m+=h*60;
        if(t[num]==-1) {
            t[num]=m;
        }else{
            pay[num]+=m-t[num];
            t[num]=-1;
        }
    }
    for(int i=0;i<10000;i++){
        if(t[i]!=-1) pay[i]+=23*60+59-t[i];
    }
    for(auto [k,v] : pay){
        int total = fees[1];
        if(v>fees[0]) total+=ceil((double)(v-fees[0])/fees[2])*fees[3];
        answer.push_back(total);
    }
    return answer;
}