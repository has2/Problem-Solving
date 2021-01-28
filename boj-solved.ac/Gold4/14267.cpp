#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int N,M,ans[100001],s[100001];
vector<int> adj[100001];
void dfs(int n,int k){
    ans[n]+=k;
    for(auto nxt : adj[n]) dfs(nxt,k);
}

int main(){
    scanf("%d%d",&N,&M);
    
    for(int i=1;i<=N;i++){
        int u;
        scanf("%d",&u);
        if(u!=-1) adj[u].push_back(i);
    }
    while(M--){
        int a,w;
        scanf("%d%d",&a,&w);
        s[a]+=w;
    }
    for(int i=2;i<=N;i++){
        if(s[i]>0) dfs(i,s[i]);
    }
    for(int i=1;i<=N;i++) printf("%d ",ans[i]);
}