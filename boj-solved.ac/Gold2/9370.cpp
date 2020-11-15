#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int tc,N,M,T,S,G[2],cand[100];
vector<pair<int,int>> adj[2001];

int dist[2001][2],par[2001],INF=9e7;

void dijk(int k){

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,S});
    dist[S][k] = 0;
    while(!pq.empty()){
        auto qt = pq.top(); pq.pop();
        int curd = qt.first;
        int curp = qt.second;

        if(curd > dist[curp][k]) continue;

        for(auto nxt : adj[curp]){
            int nd = nxt.first;
            int np = nxt.second;
            if(dist[np][k] > curd + nd){
                par[np] = curp;
                dist[np][k] = curd+nd;
                pq.push({dist[np][k],np});
            }
        }
    }
}

void solve(){

    scanf("%d%d%d%d%d%d",&N,&M,&T,&S,&G[0],&G[1]);
    for(int i=0;i<2001;i++) adj[i].clear();
    for(int i=0;i<M;i++){
        int a,b,d;
        scanf("%d%d%d",&a,&b,&d);
        adj[a].push_back({d,b});
        adj[b].push_back({d,a});
    }
    for(int i=1;i<=N;i++) dist[i][1] = dist[i][0] = INF;
    for(int i=0;i<T;i++) scanf("%d",&cand[i]);
    
    dijk(0);
    int org;
    for(int j=0;j<2;j++){
        for(auto& a : adj[G[j]]){
            if(a.second == G[1-j]) {
                org = a.first;
                a.first = 0;
            }
        }
    }         
    dijk(1);

    bool ok = 0;
    vector<int> ans;
    for(int i=0;i<T;i++){
        if(cand[i]==S) continue;
        int d = cand[i];
        while(d!=S){
            int j;
            for(j=0;j<2;j++){
                if(d==G[j]) break;
            }
            if(par[G[j]] == G[1-j]){
                ok = 1;
                break;
            }
            d = par[d];
        }
        if(ok && dist[cand[i]][1]+org==dist[cand[i]][0]){
            ans.push_back(cand[i]);
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
    puts("");
}

int main(){
    scanf("%d",&tc);
    while(tc--) solve();
}
