#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;
int N,M,K,inf=9e8;
vector<pair<int,int>> adj[251];
int s,e,dist[251][251];
void dijk(){
    fill(dist[s],dist[s]+N+1,inf);
    priority_queue<pair<int,int>> pq;
    dist[s][s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        auto qt = pq.top(); pq.pop();
        int cur = qt.second, cd=-qt.first;
        if(cd > dist[s][cur]) continue;
        for(auto next : adj[cur]){
            int nxt = next.first, nd = cd+next.second;
            if(dist[s][nxt] > nd){
                dist[s][nxt] = nd;
                pq.push({-nd,nxt});
            }
        }
    }
}
int main(){
    scanf("%d%d",&N,&M);
    while(M--){
        int u,v,k;
        scanf("%d%d%d",&u,&v,&k);
        adj[u].push_back({v,0});
        adj[v].push_back({u,!k});
    }
    scanf("%d",&K);
    memset(dist,-1,sizeof(dist));
    while(K--){
        scanf("%d%d",&s,&e);
        if(dist[s][s]==-1) dijk();
        printf("%d\n",dist[s][e]);
    }
}