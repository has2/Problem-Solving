#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
int N,M,visit[10001];
vector<int> adj[10001];
map<int,vector<int>> mp;
int dfs(int n){
    visit[n]=1;
    int ret=1;
    for(auto nxt : adj[n]){
        if(!visit[nxt]){
            ret+=dfs(nxt);
        }
    }
    return ret;
}
int main(){
    scanf("%d%d",&N,&M);
    while(M--){
        int u,v;scanf("%d%d",&u,&v);adj[v].push_back(u);
    }
    for(int i=1;i<=N;i++){
        memset(visit,0,sizeof(visit));
        mp[dfs(i)].push_back(i);
    }
    auto [k,res] = *mp.rbegin();
    sort(res.begin(),res.end());
    for(auto a : res) printf("%d ",a);
}