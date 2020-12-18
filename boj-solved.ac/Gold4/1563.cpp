#include <cstdio>
#include <cstring>
int N,dp[1001][4][4],mod=1000000;
int sol(int n,int l,int a){
    if(l==2 || a==3) return 0;
    if(n==N) return 1;
    int& ret =dp[n][l][a];
    if(ret!=-1) return ret;
    return ret = (sol(n+1,l,0)+sol(n+1,l+1,0)+sol(n+1,l,a+1))%mod;
}
int main(){
    scanf("%d",&N);
    memset(dp,-1,sizeof(dp));
    printf("%d",sol(0,0,0));
}