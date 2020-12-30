#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int N,K,pt[100][2],pr[100][2],dp[100][100001];
int sol(int n,int k){
    if(k>K) return -9e8;
    if(n==N) return 0;
    int& ret = dp[n][k];
    if(ret!=-1) return ret;
    ret = max(sol(n+1,k+pt[n][0])+pr[n][0],sol(n+1,k+pt[n][1])+pr[n][1]);
    return ret;
}
int main(){
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++) scanf("%d%d%d%d",&pt[i][0],&pr[i][0],&pt[i][1],&pr[i][1]);
    memset(dp,-1,sizeof(dp));
    printf("%d",sol(0,0));
}