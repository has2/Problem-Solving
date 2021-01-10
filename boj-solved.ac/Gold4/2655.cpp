#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct P{
    int idx,width,height,weight;
};
int N,dp[101],par[101];
P a[101];
bool cmp(P& u,P& v){
    if(u.width > v.width) return 1;
    else if(u.width == v.width) return u.weight > v.weight;
    return 0;
}
int sol(int n){
    int& ret = dp[n];
    if(ret !=-1) return ret;
    ret = a[n].height;
    for(int i=n+1;i<=N;i++){
        if(a[n].weight > a[i].weight && ret < a[n].height+sol(i)) {
            ret = a[n].height+sol(i);
            par[n]=i;
        }
    }
    return ret;
}
void prt(int n,int cnt){
    if(n==0) {
        printf("%d\n",cnt);
        return;
    }
    prt(par[n],cnt+1);
    printf("%d\n",a[n].idx);
}
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++) {
        scanf("%d%d%d",&a[i].width,&a[i].height,&a[i].weight);
        a[i].idx=i;
    }
    sort(a+1,a+1+N,cmp);
    memset(dp,-1,sizeof(dp));

    a[0].weight=9e8;
    sol(0);
    prt(par[0],0);
}
