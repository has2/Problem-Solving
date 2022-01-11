#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int T,W,a[1001],dp[1001][31][2];
int sol(int t,int w,int k){
    if(t>T) return 0;
    int& ret = dp[t][w][k];
    if(ret!=-1) return ret;
    ret = (k==a[t]) + sol(t+1,w,k);
    if(w<W) ret = max(ret,(k!=a[t]) + sol(t+1,w+1,!k));
    return ret;
}
int main(){
    scanf("%d%d",&T,&W);
    for(int i=1;i<=T;i++) {
        scanf("%d",&a[i]);
        a[i]--;
    }
    memset(dp,-1,sizeof(dp));
    printf("%d",sol(1,0,0));
}