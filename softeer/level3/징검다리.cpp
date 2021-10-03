#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N,a[3001],dp[3001];
int sol(int n){
    int& ret = dp[n];
    if(ret!=-1) return ret;
    ret=0;
    for(int i=n+1;i<=N;i++)
        if(a[n]<a[i]) ret=max(ret,1+sol(i));
    return ret;
}
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++) scanf("%d",&a[i]);
    memset(dp,-1,sizeof(dp));
    printf("%d",sol(0));
}