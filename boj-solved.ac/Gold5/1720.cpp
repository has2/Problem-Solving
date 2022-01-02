#include <cstdio>
int N,dp[31];
int main(){
    scanf("%d",&N);
    dp[1]=dp[0]=1;
    for(int i=2;i<=N;i++) dp[i]=dp[i-1]+dp[i-2]*2;
    int t=dp[N/2];
    if(N%2==0) t+=2*dp[N/2-1];
    printf("%d",(dp[N]-t)/2+t);
}