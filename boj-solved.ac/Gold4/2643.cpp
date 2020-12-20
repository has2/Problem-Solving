#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct P{
    int u,v;
};
int N,dp[101];
P a[101];
bool cmp(P& a,P& b){
    if(a.u > b.u) return 1;
    else if(a.u==b.u) return a.v > b.v;
    return 0;
}
int sol(int n){
    int& ret = dp[n];
    if(ret!=-1) return ret;
    ret = 0;
    for(int i=n+1;i<=N;i++) if(a[i].v <= a[n].v) ret = max(ret,sol(i));
    return ret += 1;
}
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        if(u<v) swap(u,v);
        a[i].u=u, a[i].v=v;
    }
    a[0].u=a[0].v=9e8;
    sort(a,a+N+1,cmp);
    memset(dp,-1,sizeof(dp));
    printf("%d",sol(0)-1);
}