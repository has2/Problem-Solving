#include <cstdio>
#include <queue>
#include <functional>
#include <algorithm>
#include <cmath>
using namespace std;
int N,M;
int level[10001];
vector<pair<int,int>> adj[10001];
int main(){
    scanf("%d%d",&N,&M);
    while(M--){
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=1;i<=N;i++) level[i]=1e9;
    pq.push({0,1});
    level[1]=0;

    while(!pq.empty()){
        auto [clv,cur] = pq.top(); pq.pop();
        if(clv!=level[cur]) continue;

        for(auto [nxt,lv] : adj[cur]){
            int nlv = max(lv,clv);
            if(nlv < level[nxt]){
                level[nxt]=nlv;
                pq.push({nlv,nxt});
            }
        }
    }
    for(int i=level[N]+1;;i++){
        bool ok=1;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0) {
                ok=0;
                break;
            }
        }
        if(ok) {
            printf("%lld",i);
            return 0;
        }
    }
}
