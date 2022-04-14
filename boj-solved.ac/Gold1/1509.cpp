#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
string s;
int N,dp[2501][2501],dp2[2501];
int sol(int l,int r){
    if(l>=r) return 1;
    int& ret = dp[l][r];
    if(ret!=-1) return ret;
    if(s[l]==s[r]) ret=sol(l+1,r-1);
    else ret=0;
    return ret;
}
int sol2(int n){
    if(n==N) return 0;
    int& ret = dp2[n];
    if(ret!=-1) return ret;
    ret=9e8;
    for(int i=n;i<N;i++)
        if(dp[n][i]) ret=min(ret,1+sol2(i+1));
    return ret;
}
int main(){
    cin >> s;
    N=s.size();
    memset(dp,-1,sizeof(dp));
    memset(dp2,-1,sizeof(dp2));
    for(int i=0;i<s.size()-1;i++)
        for(int j=i+1;j<s.size();j++) sol(i,j);
    cout << sol2(0);
}