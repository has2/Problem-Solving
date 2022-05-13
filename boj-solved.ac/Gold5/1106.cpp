#include <cstdio>
#include <algorithm>
using namespace std;
int C,N,p[20],cost[20],dp[1001],inf=9e8;
int main(){
    scanf("%d%d",&C,&N);
    for(int i=0;i<N;i++) scanf("%d%d",&cost[i],&p[i]);
    for(int i=1;i<=C;i++) dp[i]=inf;
    for(int i=0;i<N;i++){
        for(int j=1;j<=C;j++){
            for(int k=1;;k++){
                int v=0;
                if(j-p[i]*k>=0) v=dp[j-p[i]*k];
                if(dp[j] > v+cost[i]*k) dp[j] = v+cost[i]*k;
                else break;
            }
        }
    }
    printf("%d",dp[C]);
}