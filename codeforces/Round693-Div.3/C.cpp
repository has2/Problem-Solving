#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int tc,N,a[200001],dp[200001];
int sol(int n){
    if(n > N) return 0;
    int& ret = dp[n];
    if(ret!=-1) return ret;
    ret = a[n]+sol(n+a[n]);
    return ret;
}
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&N);
        for(int i=1;i<=N;i++) scanf("%d",&a[i]);
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for(int i=1;i<=N;i++) ans = max(ans,sol(i));
        printf("%d\n",ans);
    }
}
