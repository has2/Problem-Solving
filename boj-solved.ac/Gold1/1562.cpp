#include <cstdio>
#include <cstring>
using namespace std;
int N,dp[101][10][1<<10],mod=1e9;
int sol(int n,int m,int bit){
    if(n==N) return ((1<<m)|bit)==((1<<10)-1);
    
    int& ret = dp[n][m][bit];
    if(ret!=-1) return ret;
    ret=0;
    bit |= (1<<m);
    if(m-1>=0) ret=(ret+sol(n+1,m-1,bit))%mod;
    if(m+1<10) ret=(ret+sol(n+1,m+1,bit))%mod;
    return ret;
}
int main(){
    scanf("%d",&N);
    memset(dp,-1,sizeof(dp));
    int ans=0;
    for(int i=1;i<10;i++){
        ans+=sol(1,i,0);
        ans%=mod;
    }
    printf("%d",ans);
}