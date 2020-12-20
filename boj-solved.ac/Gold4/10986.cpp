#include <cstdio>
int N,M,cnt[1001],sum[1000001];
long long ans;
int main(){
    scanf("%d%d",&N,&M);
    cnt[0]++;
    for(int i=1;i<=N;i++) {
        int v;
        scanf("%d",&v);
        sum[i] = (sum[i-1]+v)%M;
        cnt[sum[i]]++;
    } 
    for(int i=0;i<M;i++){
        int n = cnt[i];
        if(n>1) ans+= ((long long)n*(n-1))/2;
    }
    printf("%lld",ans);
}
