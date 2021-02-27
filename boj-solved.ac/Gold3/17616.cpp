#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
vector<int> adj[2][100001];
bool visit[100001];
int N,M,X,k;
int dfs(int n){
    visit[n]=1;
    int ret=1;
    for(auto v : adj[k][n]){
        if(!visit[v]) ret+=dfs(v);
    }
    return ret;
}
int main(){
    scanf("%d%d%d",&N,&M,&X);
    for(int i=0;i<M;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        adj[0][u].push_back(v);
        adj[1][v].push_back(u);
    }
    int U,V;
    U=N-dfs(X)+1;
    k=1;
    V=dfs(X);
    printf("%d %d",V,U);
}