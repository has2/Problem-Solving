#include <cstdio>
#include <algorithm>
using namespace std;
int N,P[1001],dp[1001];
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++) scanf("%d",&P[i]);
    for(int i=1;i<=N;i++) dp[i]=1e8;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i-j>=0) dp[i]=min(dp[i],P[j]+dp[i-j]);
        }
    }
    printf("%d",dp[N]);
}