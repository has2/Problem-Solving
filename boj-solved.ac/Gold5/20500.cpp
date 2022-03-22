#include <cstdio>
int N,mod=1e9+7,dp[1600][3];
int main(){
    scanf("%d",&N);
    dp[2][0]=dp[2][1]=1;
    for(int i=3;i<=N;i++){
        dp[i][0]=(dp[i-1][1]+dp[i-1][2])%mod;
        dp[i][1]=(dp[i-1][2]+dp[i-1][0])%mod;
        dp[i][2]=(dp[i-1][1]+dp[i-1][0])%mod;
    }
    printf("%d",dp[N][0]);
}