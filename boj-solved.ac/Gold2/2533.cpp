#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int mxN = 1e6+1;
int N,dp[mxN][2];
vector<int> adj[mxN];
int sol(int cur,bool e,int par){
    int& ret = dp[cur][e];
    if(ret != -1) return ret;
    ret = e;
    for(auto nxt : adj[cur]){
        if(nxt!=par) ret += e ? min(sol(nxt, 0, cur), sol(nxt, 1, cur)) : sol(nxt, 1, cur);
    }
    return ret;
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dp,-1,sizeof(dp));
    printf("%d",min(sol(1,0,-1),sol(1,1,-1)));
}