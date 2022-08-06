#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N,a[100001],b[100001],c[100001],dp[100001];
int sol(int n){
    if(n>=N) return 0;
    int& ret = dp[n];
    if(ret!=-1) return ret;
    return ret=max(c[n]+sol(n+2),sol(n+1));
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
    memset(dp,-1,sizeof(dp));
    printf("%d",sol(0));
}