#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int T,N,M,D,dp[1001];
vector<pair<int,int>> adj[1001];
int sol(int n,int p){
    int& ret = dp[n];
    if(ret!=-1) return ret;
    ret=0;
    if(p!=0&&adj[n].size()==1) ret=1e8;
    else{
        for(auto [nxt,d] : adj[n]){
            if(nxt!=p) ret+=min(d,sol(nxt,n));
        }
    }
    return ret;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        for(int i=1;i<=N;i++) adj[i].clear();
        while(M--){
            int u,v,d;
            scanf("%d%d%d",&u,&v,&d);
            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }
        memset(dp,-1,sizeof(dp));
        printf("%d\n",sol(1,0));
    }
}