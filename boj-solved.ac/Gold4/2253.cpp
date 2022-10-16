#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N,M,dp[10001][500],a[10000],inf=9e8;
int sol(int n,int k){
    if(n==N) return 0;
    if(n>N||a[n]) return -1;

    int& ret = dp[n][k];
    if(ret!=-1) return ret;

    ret=inf;
    for(int i=k-1;i<=k+1;i++){
        if(i<1) continue;
        int v = sol(n+i,i);
        if(v==-1) continue;
        ret=min(ret,v);
    }
    if(ret==inf) return ret=-1;
    ret++;
    return ret;
}
int main(){
    scanf("%d%d",&N,&M);
    while(M--){
        int v;
        scanf("%d",&v);
        a[v]=1;
    }
    memset(dp,-1,sizeof(dp));
    int ans = sol(2,1);
    if(ans==-1) puts("-1");
    else printf("%d",ans+1);
}