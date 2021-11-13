#include <cstdio>
#include <set>
using namespace std;
int idx,N,a[100001];
set<int> adj[100001];
int dfs(int prev,int n){
    idx++;
    if(adj[n].find(prev) != adj[n].end()) adj[n].erase(prev);
    while(!adj[n].empty()){
        int v = a[idx];
        if(adj[n].find(v) == adj[n].end()) return 0;
        adj[n].erase(v);
        bool ret = dfs(n,v);
        if(!ret) return 0;
    }
    return 1;
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    printf("%d",dfs(0,1));
}