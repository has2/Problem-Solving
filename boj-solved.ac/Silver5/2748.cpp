#include <cstdio>
int n;
long long dp[91];
int main(){
    scanf("%d",&n);
    dp[1]=1;
    for(int i=2;i<=n;i++) dp[i] = dp[i-1]+dp[i-2];
    printf("%lld",dp[n]);
}