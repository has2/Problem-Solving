#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N,Q,dist[5001][5001];
vector<pair<int,int>> adj[5001];
bool visit[5001];
void dfs(int s,int prev,int cur,int v){
    for(auto [nxt,d] : adj[cur]){
        if(nxt!=prev){
            int t = min(v,d);
            dist[s][nxt]=t;
            dfs(s,cur,nxt,t);
        }
    }
}
int main(){
    scanf("%d%d",&N,&Q);
    for(int i=0;i<N-1;i++){
        int u,v,d;
        scanf("%d%d%d",&u,&v,&d);
        adj[u].push_back({v,d});
        adj[v].push_back({u,d});
    }
    for(int i=1;i<=N;i++){
        dfs(i,-1,i,2e9);
    }
    while(Q--){
        int k,v,cnt=0;
        scanf("%d%d",&k,&v);
        for(int i=1;i<=N;i++){
            if(dist[i][v] >= k) cnt++;
        }
        printf("%d\n",cnt);
    }
}