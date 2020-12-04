#include <cstdio>
#include <vector>
using namespace std;
using ll = long long;
int N,M;
vector<pair<int,ll>> adj[501];
ll dist[501],inf=1e18;
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        adj[a].push_back({b,c});
    }

    for(int i=1;i<=N;i++) dist[i] = inf;
    dist[1] = 0;
    bool cycle = 0;
    for(int i=0;i<N;i++){
        for(int j=1;j<=N;j++){
            for(auto& p : adj[j]){
                int nxt = p.first, cost=p.second;
                if(dist[j] != inf && dist[nxt] > dist[j]+cost){
                    dist[nxt] = dist[j]+cost;
                    if(i==N-1) cycle = 1;
                }
            }
        }
    }
    if(cycle) puts("-1");
    else{
        for(int i=2;i<=N;i++) printf("%lld\n",dist[i]==inf ? -1 : dist[i]);
    }
}