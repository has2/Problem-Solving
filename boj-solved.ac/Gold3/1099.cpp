#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
string s,word[50];
int dp[51],N,inf=9e8;
int cost(string a,string b){
    if(a.size()!=b.size()) return inf;
    string ta = a;
    string tb = b;
    sort(ta.begin(),ta.end());
    sort(tb.begin(),tb.end());
    if(ta!=tb) return inf;

    int ret = a.size();
    for(int i=0;i<a.size();i++){
        if(a[i]==b[i]) ret--;
    }
    return ret;
}
int minCost(string k){
    int ret = inf;
    for(int i=0;i<N;i++) ret = min(ret,cost(k,word[i]));
    return ret;
}
int sol(int n){
    if(n==s.size()) return 0;
    int& ret = dp[n];
    if(ret!=-1) return ret;
    ret = inf;
    for(int i=n;i<s.size();i++){
        string k = s.substr(n,i-n+1);
        int c = minCost(k);
        if(c==inf) continue;
        ret = min(ret,c+sol(i+1));
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin >> s >> N;
    for(int i=0;i<N;i++) cin >> word[i];
    memset(dp,-1,sizeof(dp));
    printf("%d",sol(0)==inf ? -1 : sol(0));
}