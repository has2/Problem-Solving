#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N,M;
vector<pair<int,int>> adj[101];
int in[101],cnt[101];
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++){
        int x,y,k;
        scanf("%d%d%d",&x,&y,&k);
        adj[x].push_back({y,k});
        in[y]++;
    }
    vector<int> ans;
    queue<int> q;
    q.push(N);
    cnt[N]=1;
    while(!q.empty()){
        int cur=q.front(); q.pop();
        if(adj[cur].empty()){
            ans.push_back(cur);
        }
        for(auto p : adj[cur]){
            int nxt=p.first;
            int c=p.second;
            cnt[nxt]+=cnt[cur]*c;
            if(--in[nxt]==0) q.push(nxt);
        }
    }
    sort(ans.begin(),ans.end());
    for(auto k : ans) printf("%d %d\n",k,cnt[k]);
}