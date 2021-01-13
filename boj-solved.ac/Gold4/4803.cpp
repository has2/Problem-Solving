#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int N,M,visit[501],tc;
vector<int> adj[501];
bool ok =1;
void dfs(int n,int cnt){
    visit[n]=cnt;
    for(auto nxt : adj[n]){
        if(!visit[nxt]) dfs(nxt,cnt+1);
        else if(visit[n]-visit[nxt]>1) ok=0;
    }
}
int main(){
    while(1){
        scanf("%d%d",&N,&M);
        memset(visit,0,sizeof(visit));
        for(int i=0;i<=N;i++) adj[i].clear();
        if(N==0) break;
        while(M--){
            int u,v;
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = 0;
        for(int i=1;i<=N;i++){
            if(!visit[i]){
                ok=1;
                dfs(i,0);
                ans+=ok;
            }
        }
        printf("Case %d: ",++tc);
        if(ans==0) puts("No trees.");
        else if(ans==1) puts("There is one tree.");
        else printf("A forest of %d trees.\n",ans);
    }
}
