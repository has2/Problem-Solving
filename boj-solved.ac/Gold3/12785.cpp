#include <cstdio>
#include <cstring>
using namespace std;
int w,h,mod=1000007,ax,ay,dp[201][201];

int sol(int y,int x){
    if(y==ay&&x==ax) return 1;

    int& ret = dp[y][x];
    if(ret!=-1) return ret;
    ret=0;
    if(y+1<=h) ret = sol(y+1,x);
    if(x+1<=w) ret += sol(y,x+1);
    return ret%=mod;
}
int main(){
    scanf("%d%d%d%d",&w,&h,&ax,&ay);

    memset(dp,-1,sizeof(dp));
    long long ans=sol(1,1);

    int sy=ay,sx=ax;
    ay=h,ax=w;

    memset(dp,-1,sizeof(dp));
    ans*=sol(sy,sx);
    
    printf("%lld",ans%mod);
}