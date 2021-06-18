#include <cstdio>
#include <cstring>
using namespace std;
int tc,N,M,a[20],dp[10001];
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&N);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<N;i++) scanf("%d",&a[i]);
        scanf("%d",&M);
        dp[0]=1;
        for(int i=0;i<N;i++)
            for(int j=1;j<=M;j++)
                if(j-a[i]>=0) dp[j]+=dp[j-a[i]];
        printf("%d\n",dp[M]);
    }
}
