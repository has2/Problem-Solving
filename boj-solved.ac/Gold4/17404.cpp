#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N,cost[1000][3],dp[1000][3],INF=1e9;
int ans=INF;
int sol(int s){
    for(int i=0;i<N;i++) for(int j=0;j<3;j++) dp[i][j] = INF;
    dp[0][s] = cost[0][s];
    int ret = INF;
    for(int i=1;i<N;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(j!=k) dp[i][j] = min(dp[i][j],dp[i-1][k]+cost[i][j]);
            }
        }
    }
    for(int i=0;i<3;i++) if(i!=s) ret = min(ret,dp[N-1][i]);
    return ret;
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) 
        for(int j=0;j<3;j++) scanf("%d",&cost[i][j]);
    for(int i=0;i<3;i++){
        int ret = sol(i);
        ans = min(ans,ret);
    }
    printf("%d",ans);
}