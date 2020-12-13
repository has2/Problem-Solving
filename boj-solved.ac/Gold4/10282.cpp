#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int tc,N,D,C,INF=9e8;
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d%d",&N,&D,&C);
        vector<vector<pair<int,int>>> adj(N+1);
        vector<int> in(N+1), dist(N+1,INF);
        for(int i=0;i<D;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            adj[b].push_back({a,c});
            in[a]++;
        }
        priority_queue<pair<int,int>> pq;
        dist[C]=0;
        pq.push({C,0});
        while(!pq.empty()){

            auto qt = pq.top(); pq.pop();

            if(dist[qt.first] < -qt.second) continue;

            for(auto p : adj[qt.first]){
                int nxt = p.first, cost = p.second;
                if(dist[nxt] > dist[qt.first]+cost){
                    dist[nxt] = dist[qt.first]+cost;
                    pq.push({nxt,dist[nxt]});
                }
            }
        }
        int cnt=0,mx=0;
        for(int i=1;i<=N;i++) {
            if(dist[i]!=INF){
                cnt++;
                mx=max(mx,dist[i]);
            }
        }
        printf("%d %d\n",cnt,mx);
    }
}