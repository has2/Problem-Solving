#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N,dp[5001][5001],inf=9e8;
string s;
int sol(int l,int r){
    if(l>=r) return 0;
    int& ret = dp[l][r];
    if(ret!=-1) return ret;
    ret = inf;
    if(s[l]==s[r]) ret = min(ret,sol(l+1,r-1));
    ret = min(ret,1+sol(l+1,r));
    ret = min(ret,1+sol(l,r-1));
    return ret;
}
int main(){
    cin >> N >> s;
    memset(dp,-1,sizeof(dp));
    cout << sol(0,N-1);
}
