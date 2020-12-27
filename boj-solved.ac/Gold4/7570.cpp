#include <algorithm>
#include <cstdio>
using namespace std;
int N,dp[1000001],v,ans;
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",&v);
        dp[v] = dp[v-1]+1;
        ans = max(ans,dp[v]);
    }
    printf("%d",N-ans);
}