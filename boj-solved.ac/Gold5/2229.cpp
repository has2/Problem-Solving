#include <cstdio>
#include <algorithm>
using namespace std;
int N,dp[1001],a[1001];
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++) scanf("%d",&a[i]);
    for(int i=2;i<=N;i++){
        int minv=a[i],maxv=a[i];
        for(int j=i-1;j>=0;j--){
            maxv=max(a[j+1],maxv);
            minv=min(a[j+1],minv);
            dp[i] = max(dp[i],dp[j]+maxv-minv);
        }
    }
    printf("%d",dp[N]);
}