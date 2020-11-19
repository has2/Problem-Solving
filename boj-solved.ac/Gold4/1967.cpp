#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int N,ans,mxN,mxV;
bool visit[10001];
vector<pair<int,int>> adj[10001];
void dfs(int n,int c){
    visit[n] = 1;
    if(c>mxV){
        mxV=c;
        mxN=n;
    }
    for(auto nxt : adj[n]){
        if(!visit[nxt.first]) dfs(nxt.first,c+nxt.second);
    }
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N-1;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    dfs(1,0);
    memset(visit,0,sizeof(visit));
    mxV=0;
    dfs(mxN,0);
    printf("%d",mxV);
}