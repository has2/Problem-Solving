#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int K,N,time[101][101],mvtime[101][101][101],dp[101][101],inf=2e9;
int sol(int k,int n){
    if(n==N) return time[k][n];
    int& ret = dp[k][n];
    if(ret!=-1) return ret;
    ret=inf;
    for(int i=1;i<=K;i++) ret=min(ret,sol(i,n+1)+time[k][n]+mvtime[k][n][i]);
    return ret;
}
int main(){
    scanf("%d%d",&K,&N);
    for(int j=1;j<=N;j++){
        for(int i=1;i<=K;i++) scanf("%d",&time[i][j]);
        if(j==N) break;
        for(int i=1;i<=K;i++)
            for(int k=1;k<=K;k++)
                if(i!=k) scanf("%d",&mvtime[i][j][k]);
    }
    memset(dp,-1,sizeof(dp));
    printf("%d",sol(0,0));
}