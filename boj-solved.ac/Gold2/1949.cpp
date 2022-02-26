#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int N,a[10001],dp[10001][2];
vector<int> adj[10001];
int sol(int n,int k,int p){
    int& ret = dp[n][k];
    if(ret!=-1) return ret;
    ret=0;
    if(k==1) ret=a[n];
    for(auto nxt : adj[n]){
        if(nxt!=p){
            if(k==0) ret+=max(sol(nxt,0,n),sol(nxt,1,n));
            else ret+=sol(nxt,0,n);
        }
    }
    return ret;
}
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++) scanf("%d",&a[i]);
    for(int i=0;i<N-1;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    adj[0].push_back(1);
    memset(dp,-1,sizeof(dp));
    printf("%d",sol(0,0,0));
}