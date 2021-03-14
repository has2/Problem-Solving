#include <cstdio>
#include <cstring>
using ll = long long ;
int N,mod=987654321;
ll dp[10001];
ll sol(int n){
    if(n==0||n==2) return 1;
   
    ll& ret = dp[n];
    if(ret!=-1) return ret;
    ret=0;
    for(int i=0;i<=n-2;i+=2){
        ret+=sol(i)*sol(n-2-i);
        ret%=mod;
    }
    return ret;
}
int main(){
    scanf("%d",&N);
    memset(dp,-1,sizeof(dp));
    printf("%lld",sol(N));
}