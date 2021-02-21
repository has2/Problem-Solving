#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
using ll = long long;
int V,E,M,X,Y;
vector<pair<int,int>> adj[10002];
ll dist[10002],md[10002],ans=1e12;
bool mac[10002],star[10002];
void dijk(int n){
    for(int i=0;i<=V+1;i++) dist[i]=1e12;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    pq.push({0,n});
    dist[n]=0;
    while(!pq.empty()){
        auto qt = pq.top(); pq.pop();
        if(dist[qt.second] < qt.first) continue;
        for(auto p : adj[qt.second]){
            ll nxt = p.first;
            int cost = p.second;
            if(qt.first+cost<dist[nxt]){
                dist[nxt]=qt.first+cost;
                pq.push({qt.first+cost,nxt});
            }
        }
    }
}

int main(){
    scanf("%d%d",&V,&E);
    while(E--){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    scanf("%d%d",&M,&X);
    while(M--){
        int v;
        scanf("%d",&v);
        mac[v]=1;
        adj[0].push_back({v,0});
    }
    scanf("%d%d",&M,&Y);
    while(M--){
        int v;
        scanf("%d",&v);
        star[v]=1;
        adj[V+1].push_back({v,0});
    }
    dijk(0);
    for(int i=0;i<=V+1;i++) md[i]=dist[i];
    dijk(V+1);

    for(int i=1;i<=V;i++){
        if(mac[i]||star[i]) continue;
        if(md[i]<=X&&dist[i]<=Y) ans = min(md[i]+dist[i],ans);
    }

    if(ans<1e12) printf("%lld",ans);
    else puts("-1");
}