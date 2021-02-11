#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int N,K,dp[50][50][13000];
string r;
int sol(int n,int a,int k){
    if(n==N) return k==K;
    int& ret = dp[n][a][k];
    if(ret!=-1) return ret;

    int b = n-a;
    if(sol(n+1,a+1,k)){
        r = 'A' + r;
        return ret=1;
    }

    if(sol(n+1,a,k+a)){
        r = 'B' + r;
        return ret=1;
    }
    return ret=0;
}
int main(){
    cin >> N >> K;
    memset(dp,-1,sizeof(dp));
    sol(0,0,0);
    if(r=="") cout << -1;
    else cout << r;
}