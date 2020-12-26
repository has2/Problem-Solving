#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int N,M,K,adj[301][301],dp[301][301];
int sol(int n,int m){
    if(n==N) return 0;
    if(m==M) return -9e8;
    int& ret = dp[n][m];
    if(ret!=-1) return ret;
    ret = -9e8;
    for(int i=1;i<=N;i++) if(adj[n][i]) ret = max(ret,adj[n][i]+sol(i,m+1)); 
    return ret;
}
int main(){
    scanf("%d%d%d",&N,&M,&K);
    while(K--){
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        if(u<v) adj[u][v] = max(adj[u][v],c);
    }
    memset(dp,-1,sizeof(dp));
    printf("%d",sol(1,1) > 0 ? sol(1,1):0);
}