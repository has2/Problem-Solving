#include <cstdio>
#include <algorithm>
using namespace std;
int N,T,dp[10001];
pair<int,int> p[100];
int main(){
    scanf("%d%d",&N,&T);
    for(int i=0;i<N;i++) scanf("%d%d",&p[i].first,&p[i].second);
    for(int i=0;i<N;i++){
        for(int j=T;j>=0;j--){
            if(j-p[i].first>=0) dp[j] = max(dp[j],dp[j-p[i].first]+p[i].second);
        }
    }
    int ans=0;
    for(int i=1;i<=T;i++) ans=max(ans,dp[i]);
    printf("%d",ans);
}