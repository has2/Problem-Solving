#include <cstdio>
using ll = long long;
int N;
ll K,P,mod=1000000007;
int main(){
    scanf("%lld%lld%d",&K,&P,&N);
    while(N--) K=(K*P)%mod;
    printf("%lld",K);
}