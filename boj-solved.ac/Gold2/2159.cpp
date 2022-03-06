#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>
#include <queue>
using namespace std;
using ll = long long;
struct P{
    int u,v,d;
};
int N,dy[4]={-1,1,0,0},dx[4]={0,0,1,-1},id;
ll dist[800001];
vector<P> a[100001];
vector<pair<ll,int>> adj[800001];
bool inRange(int y,int x){
    return y>=0&&x>=0&&y<=100000&&x<=100000;
}
int main(){
    scanf("%d",&N);
    N++;
    for(int i=0;i<N;i++) {
        int y,x;
        scanf("%d%d",&y,&x);
        a[i].push_back({y,x,id++});
        if(i==0) continue;
        for(int k=0;k<4;k++){
            int ny=y+dy[k],nx=x+dx[k];
            if(inRange(ny,nx)) a[i].push_back({ny,nx,id++});
        }
    }
    for(int i=1;i<N;i++){
        for(int j=0;j<a[i-1].size();j++){
            for(int k=0;k<a[i].size();k++){
                int d = abs(a[i-1][j].u-a[i][k].u)+abs(a[i-1][j].v-a[i][k].v);
                adj[a[i-1][j].d].push_back({a[i][k].d,d});
            }
        }
    }
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    pq.push({0,0});
    for(int i=0;i<id;i++) dist[i]=9e15;
    dist[0]=0;

    while(!pq.empty()){
        auto [d,cur] = pq.top(); pq.pop();
        if(dist[cur]!=d) continue;
        for(auto [nxt,cost] : adj[cur]){
            if(d+cost < dist[nxt]){
                dist[nxt]=d+cost;
                pq.push({dist[nxt],nxt});
            }
        }
    }
    ll ans=9e15;
    for(auto [u,v,id] : a[N-1]) ans=min(ans,dist[id]);
    printf("%lld",ans);
}