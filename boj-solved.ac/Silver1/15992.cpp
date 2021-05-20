#include <cstdio>
#include <cstring>
int t,n,m,dp[1001][1001],mod = 1e9+9;
int main(){
    scanf("%d",&t);
    dp[1][1]=dp[2][1]=dp[3][1]=1;
    for(int i=2;i<=1000;i++){
        for(int j=1;j<=1000;j++){
            for(int k=1;k<4;k++){
                if(j-k>0) dp[j][i]+=dp[j-k][i-1];
                dp[j][i]%=mod;
            }
        }
    }
    while(t--){
        scanf("%d%d",&n,&m);
        printf("%d\n",dp[n][m]);
    }
}