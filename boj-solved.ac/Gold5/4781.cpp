#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,dp[10001],cal[5000],price[5000];
int main(){
    while(1){
        float f;
        scanf("%d%f",&n,&f);
        if(n==0) break;
        m=f*100+0.5;
        for(int i=0;i<n;i++) {
            scanf("%d%f",&cal[i],&f);
            price[i]=100*f;
        }
        memset(dp,0,sizeof(dp));
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=1;j<=m;j++){
                if(j-price[i]>=0) {
                    dp[j] = max(dp[j],dp[j-price[i]]+cal[i]);
                    ans=max(ans,dp[j]);
                }
            }
        }
        printf("%d\n",ans);
    }
}