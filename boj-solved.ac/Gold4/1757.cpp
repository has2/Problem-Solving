#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N,M,dp[10001][502],a[10001],inf=-9e8;
int sol(int n,int m){
    if(n==N) {
        if(m==0) return 0;
        return inf;
    }
    int& ret = dp[n][m];
    if(ret!=-1) return ret;
    ret=inf;
    if(m>0) {
        if(n+m<=N) ret=max(ret,sol(n+m,0));
    }else {
        ret=max(ret,sol(n+1,0));
    }
    
    if(m+1<=M) ret=max(ret,sol(n+1,m+1)+a[n]);
    return ret;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    memset(dp,-1,sizeof(dp));
    printf("%d",sol(0,0));
}