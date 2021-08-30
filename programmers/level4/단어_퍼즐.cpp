#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<string> str;
string t;
int dp[20001],inf=9e7;;
bool check(int n,string& s){
    for(int i=0;i<s.size();i++){
        if(n+i>=t.size()) return 0;
        if(t[n+i]!=s[i]) return 0;
    }
    return 1;
}
int sol(int n){
    if(n==t.size()) return 0;
    int& ret = dp[n];
    if(ret!=-1) return ret;
    ret=inf;
    for(auto& s : str){
        if(check(n,s)) ret=min(sol(n+s.size()),ret);
    }
    return ++ret;
}
int solution(vector<string> _strs, string _t){   
    memset(dp,-1,sizeof(dp));
    str=_strs;
    t=_t;
    return sol(0) >= inf ? -1 : sol(0);
}