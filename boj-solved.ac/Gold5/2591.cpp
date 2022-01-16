#include <iostream>
#include <string>
#include <cstring>
using namespace std;
using ll = long long;
int N;
ll dp[41];
string s;
ll sol(int n){
    if(n==N) return 1;
    ll& ret = dp[n];
    if(ret!=-1) return ret;
    ret=0;
    if(s[n]=='0') return 0;
    if(n<N-1) {
        string a = s.substr(n,2);
        if(stoi(a)<35){
            ret+=sol(n+2);
            if(a[1]=='0') return ret;
        }
    }
    ret+=sol(n+1);
    return ret;
}
int main(){
    cin >> s;
    N = s.size();
    memset(dp,-1,sizeof(dp));
    printf("%lld",sol(0));
}