#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N,M,a[100],dp[100][51],sum[100][100],inf=9e8;
int sol(int n,int m){
    if(m==M) return 0;
    if(n>=N) return -inf;
    int& ret = dp[n][m];
    if(ret!=-1) return ret;
    ret=sol(n+1,m);
    for(int i=n;i<N;i++){
        ret=max(ret,sum[n][i]+sol(i+2,m+1));
    }
    return ret;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<N;i++){
        int s = 0;
        for(int j=i;j<N;j++){
            s+=a[j];
            sum[i][j]=s;
        }
    }
    printf("%d",sol(0,0));
}

