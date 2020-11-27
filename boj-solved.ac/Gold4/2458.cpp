#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int N,M,in[501],out[501],ans;
vector<int> adj[501];
bool visit[501];
int dfs(int n){
    visit[n] = 1;
    int ret = 1;
    for(int nxt : adj[n]){
        if(!visit[nxt]){
            in[nxt]++;
            ret+=dfs(nxt);
        }
    }
    return ret;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
    }

    for(int i=1;i<=N;i++){
        memset(visit,0,sizeof(visit));
        out[i] = dfs(i);
    }
    for(int i=1;i<=N;i++) if(in[i]+out[i]==N) ans++;
    printf("%d",ans);
}