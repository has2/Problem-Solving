#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int N,dp[10001],inf=9e8;
pair<int,int> a[10001];
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++) scanf("%d%d",&a[i].first,&a[i].second);
    sort(a+1,a+N+1);
    for(int i=1;i<=N;i++){
        int mH=0;
        dp[i]=inf;  
        for(int j=i;j>=1;j--){
            mH=max(mH,abs(a[j].second));
            dp[i]=min(dp[i],dp[j-1]+max(2*mH,a[i].first-a[j].first)); 
        }
    }
    printf("%d",dp[N]);
}