#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <functional>
using namespace std;
int N,M,dist[1001];
vector<pair<int,int>> adj[1001],path;
int dijk(int a,int b){
    for(int i=1;i<=N;i++) dist[i]=9e8;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[1]=0;
    pq.push({0,1});
    while(!pq.empty()){
        auto [d,cur] = pq.top(); pq.pop();
        if(dist[cur]!=d) continue;
        for(auto [nxt,cost] : adj[cur]){
            if((cur==a&&nxt==b)||(cur==b&&nxt==b)){
                cost = 9e8;
            }
            if(dist[nxt]>d+cost){
                dist[nxt]=d+cost;
                pq.push({dist[nxt],nxt});
            }
        }
    }
    return dist[N];
}
int main(){
    scanf("%d%d",&N,&M);
    while(M--){
        int a,b,t;
        scanf("%d%d%d",&a,&b,&t);
        adj[a].push_back({b,t});
        adj[b].push_back({a,t});
        path.push_back({a,b});
    }  
    int ans=0;
    for(auto [a,b] : path) ans=max(dijk(a,b),ans);
    if(ans>=9e8) {
        puts("-1");
        return 0;
    }
    printf("%d",ans-dijk(0,0));
}