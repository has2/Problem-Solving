#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
string s;
int dp[151];
int sol(int n){
    if(n==s.size()) return 1;
    int& ret = dp[n];
    if(ret!=-1) return ret;

    if(n>=s.size()-1) return ret=0;
    string t = s.substr(n,2);

    if(t=="01" && sol(n+2)) return ret=1;
    if(n>=s.size()-3) return ret=0;
    t = s.substr(n,3);

    if(t=="100"){
        int i;
        for(i=n+3;i<s.size();i++){
            if(s[i]=='1') break;
        }
        for(int j=i;j<s.size();j++){
            if(s[j]!='1') break;
            else if(sol(j+1)) return ret=1;
        }
    }
    return ret=0;
}
int main(){
    cin >> s;
    memset(dp,-1,sizeof(dp));
    if(sol(0)) cout << "SUBMARINE";
    else cout << "NOISE";
}