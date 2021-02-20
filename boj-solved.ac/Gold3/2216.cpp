#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int A,B,C,dp[3001][3001],inf=-1e9;
string s[2];
int sol(int n,int m){
    if(n==s[0].size()) return (s[1].size()-m)*B;
    if(m==s[1].size()) return (s[0].size()-n)*B;
    int& ret = dp[n][m];
    if(ret!=inf) return ret;
    ret = B+max(sol(n+1,m),sol(n,m+1));
    ret = max((s[0][n]==s[1][m] ? A : C) + sol(n+1,m+1),ret);
    return ret;
}
int main(){
    cin >> A >> B >> C >> s[0] >> s[1];
    for(int i=0;i<3000;i++) 
        for(int j=0;j<3000;j++) dp[i][j]=inf;
    cout << sol(0,0);
}