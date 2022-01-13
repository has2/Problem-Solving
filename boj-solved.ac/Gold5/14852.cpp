#include <cstdio>
using ll = long long;
int N;
ll dp[1000001][3],m=1000000007;
int main(){
    scanf("%d",&N);
    dp[1][0]=2;
    dp[0][0]=dp[1][1]=dp[1][2]=1;
    for(int i=2;i<=N;i++){
        dp[i][0]=(2*dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-2][0])%m;
        dp[i][1]=dp[i-1][0]+dp[i-1][2];
        dp[i][2]=dp[i-1][0]+dp[i-1][1];
    }
    printf("%lld",dp[N][0]);
}