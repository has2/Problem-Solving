#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
int N,M,dist[50001];
vector<pair<int,int>> adj[50001];
int main(){
    scanf("%d%d",&N,&M);
    while(M--){
        int u,v,d;
        scanf("%d%d%d",&u,&v,&d);
        adj[u].push_back({v,d});
        adj[v].push_back({u,d});
    }
    for(int i=1;i<=N;i++) dist[i]=9e8;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    dist[1]=0;
    while(!pq.empty()){
        auto [d,cur] = pq.top(); pq.pop();
        if(dist[cur]!=d) continue;
        for(auto [nxt,nd] : adj[cur]){
            if(dist[nxt] > d+nd){
                dist[nxt]=d+nd;
                pq.push({dist[nxt],nxt});
            }
        }
    }
    printf("%d",dist[N]);
}