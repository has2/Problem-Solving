#include <string>
#include <iostream>
#include <cstring>
using namespace std;
int dp[5001];
string s;
int sol(int n){
    if(n>=s.size()) return 1;
    int& ret = dp[n];
    if(ret!=-1) return ret;
    if(s[n]=='0') return 0;
    ret=sol(n+1);
    if(n+1<s.size()){
        int k = (s[n]-'0')*10+(s[n+1]-'0');
        if(k<27) ret=(ret+sol(n+2))%1000000;
    }
    return ret;
}
int main(){
    cin >> s;
    memset(dp,-1,sizeof(dp));
    cout << sol(0);
}