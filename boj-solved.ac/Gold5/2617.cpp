#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int N,M,visit[100],adj[100][100],ans;
int dfs(int cur,int k){
    visit[cur]=1;
    int ret=1;
    for(int i=1;i<=N;i++){
        if(!visit[i]&&adj[cur][i]==k) ret+=dfs(i,k);
    }
    return ret;
}
int main(){
    scanf("%d%d",&N,&M);
    while(M--){
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u][v]=1;
        adj[v][u]=2;
    }
    for(int i=1;i<=N;i++){
        int v = dfs(i,1);
        memset(visit,0,sizeof(visit));
        if(v-1>N/2) {
            ans++;
        } else {
            v = dfs(i,2);
            if(v-1>N/2) ans++;
        }
        memset(visit,0,sizeof(visit));
    }
    printf("%d",ans);
}