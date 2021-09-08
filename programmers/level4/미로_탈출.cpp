#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
int dist[1025][1001];
bool trap[1001];
map<int,int> trapidx;
vector<pair<int,int>> adj[1025][1001];
bool isFlip(int a,vector<int>& flag){
    return trap[a] && flag[trapidx[a]];
}
int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    for(int i=0;i<traps.size();i++) {
        trap[traps[i]]=1;
        trapidx[traps[i]]=i;
    }
    for(int i=0;i<(1<<traps.size());i++){
        vector<int> flag(traps.size(),0);
        for(int j=1;j<=n;j++) dist[i][j]=9e8;
        for(int j=0;j<traps.size();j++) {
            if(i&(1<<j)) flag[j]=1;
        }
        for(auto& r : roads){
            int u=r[0],v=r[1],c=r[2];
            int cnt = isFlip(u,flag)+isFlip(v,flag);
            if(cnt==1) adj[i][v].push_back({u,c});
            else adj[i][u].push_back({v,c});
        }
    }
    queue<pair<int,int>> q;
    dist[0][start]=0;
    q.push({0,start});

    int ans=9e8;
    while(!q.empty()){
        auto [bit,cur] = q.front(); q.pop();
        if(cur==end) ans=min(ans,dist[bit][cur]);
        for(auto [nxt,d] : adj[bit][cur]){
            int nb = bit;
            if(trap[nxt]) {
                int i = trapidx[nxt];
                nb ^= (1<<i);
            }
            if(dist[nb][nxt] > dist[bit][cur]+d){
                dist[nb][nxt]=dist[bit][cur]+d;
                q.push({nb,nxt});
            }
        }
    }
    return ans;
}