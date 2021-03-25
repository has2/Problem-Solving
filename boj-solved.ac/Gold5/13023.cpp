#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int N,M,visit[2001];
vector<int> adj[2001];
bool ok=0;
void dfs(int n,int k){
    if(ok) return;
    visit[n]=1;
    if(k==5) ok=1;
    for(auto nxt : adj[n]){
        if(!visit[nxt]) dfs(nxt,k+1);
    }
    visit[n]=0;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<N;i++){
        memset(visit,0,sizeof(visit));
        dfs(i,1);
        if(ok) break;
    }
    printf("%d",ok);
}