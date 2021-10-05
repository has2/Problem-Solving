#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int K,N,time[10001][101],mvtime[101],dp[10001][101],inf=2e9;
int main(){
    scanf("%d%d",&K,&N);
    for(int j=1;j<=N;j++){
        for(int i=1;i<=K;i++) {
            scanf("%d",&time[i][j]);
            dp[i][j]=inf;
        }
        if(j==N) break;
        scanf("%d",&mvtime[j]);
    }
    for(int j=1;j<=N;j++){
        int v=inf;
        for(int i=1;i<=K;i++) v=min(v,dp[i][j-1]);
        for(int i=1;i<=K;i++) dp[i][j] = min(v+mvtime[j-1]+time[i][j],dp[i][j-1]+time[i][j]);
    }
    int ans=inf;
    for(int i=1;i<=K;i++) ans=min(dp[i][N],ans);
    printf("%d",ans);
}