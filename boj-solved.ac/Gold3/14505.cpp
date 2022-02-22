#include <string>
#include <iostream>
#include <cstring>
using namespace std;
string s;
int dp[31][31];
int sol(int l,int r){
    if(l==r) return 1;
    if(l>r) return 0;
    int& ret=dp[l][r];
    if(ret!=-1) return ret;
    ret = sol(l+1,r)+sol(l,r-1);
    if(s[l]!=s[r]) ret-=sol(l+1,r-1); 
    else ret++;
    return ret; 
}
int main(){
    cin >> s;
    memset(dp,-1,sizeof(dp));
    cout << sol(0,s.size()-1);
}