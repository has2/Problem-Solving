#include <cstdio>
#include <cstring>
using ll = long long;
using namespace std;
int N,sum[100001],base,cnt;
ll dp[5];
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++) {
        int v;
        scanf("%d",&v);
        sum[i]=sum[i-1]+v;
        if(sum[i]==0) cnt++;
    }
    if(sum[N]==0){
        if(cnt<4) puts("0");
        else printf("%lld",(ll)(cnt-1)*(cnt-2)*(cnt-3)/6);
        return 0;
    }
    if(sum[N]%4){
        puts("0");
        return 0;
    }
    base=sum[N]/4;

    dp[0]=1;
    for(int i=1;i<N;i++){
        if(sum[i]%base) continue;
        int j=sum[i]/base;
        if(j==0 || j>3) continue;
        dp[j]+=dp[j-1];
    }
    printf("%lld",dp[3]);
}