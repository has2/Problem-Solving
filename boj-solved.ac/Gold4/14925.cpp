#include <cstdio>
#include <algorithm>
using namespace std;
int M,N,map[1001][1001],dp[1001][1001];
int main(){
    scanf("%d%d",&M,&N);
    for(int i=1;i<=M;i++)
        for(int j=1;j<=N;j++) scanf("%d",&map[i][j]);
    int ans=0;
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            if(!map[i][j]){
                if(!dp[i-1][j-1] || !dp[i][j-1]|| !dp[i-1][j]) dp[i][j]=1;
                else dp[i][j]=min(min(dp[i-1][j-1],dp[i][j-1]),dp[i-1][j])+1;
                ans=max(ans,dp[i][j]);
            }
        }
    }
    printf("%d",ans);
}