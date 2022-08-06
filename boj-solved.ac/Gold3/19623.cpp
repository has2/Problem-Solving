#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct P{
    int l,r,v;
};
int N,dp[100001],s[100001];
P a[100001];
bool cmp(P& p,P& q){
    return p.l < q.l;
}
int sol(int n){
    if(n>=N) return 0;
    int& ret = dp[n];
    if(ret!=-1) return ret;
    int i = lower_bound(s+n,s+N,a[n].r)-s;
    ret = max(sol(n+1),a[n].v+sol(i));
    return ret;
}
int main(){
    scanf("%d",&N);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<N;i++) scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].v);
    sort(a,a+N,cmp);
    for(int i=0;i<N;i++) s[i] = a[i].l;
    printf("%d",sol(0));
}