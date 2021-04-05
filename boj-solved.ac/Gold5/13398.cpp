#include <cstdio>
#include <algorithm>
using namespace std;
int N,a[100000],dp[100000][2],ans;
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    dp[0][0]=a[0];
    ans=a[0];
    for(int i=1;i<N;i++){
        dp[i][0] = dp[i-1][0]<0 ? a[i] : dp[i-1][0]+a[i];
        dp[i][1] = max(dp[i-1][0],dp[i-1][1]+a[i]); 
        ans=max(dp[i][0],ans);
        ans=max(dp[i][1],ans);
    }
    printf("%d",ans);
}