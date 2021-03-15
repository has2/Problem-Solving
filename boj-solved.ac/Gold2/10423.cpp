#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
int N,M,K;
vector<pair<int,int>> adj[1001];
vector<int> p;
bool visit[1001];
int main(){
    scanf("%d%d%d",&N,&M,&K);
    for(int i=0;i<K;i++){
        int v;
        scanf("%d",&v);
        p.push_back(v);
    }
    for(int i=0;i<M;i++){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(auto a : p) {
        for(auto e : adj[a]){
            pq.push({e.second,e.first});
        }
        visit[a]=1;
    }
    int ans = 0,cnt=p.size();
    while(!pq.empty()){
        auto qt = pq.top(); pq.pop();
        int cur = qt.second;
        if(visit[cur]) continue;
        visit[cur]=1;
        ans+=qt.first;
        if(++cnt==N) break;
        for(auto e : adj[cur]){
            int nxt=e.first;
            int w=e.second;
            pq.push({w,nxt});
        }
    }
    printf("%d",ans);
}