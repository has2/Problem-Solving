#include <cstdio>
using ll = long long;
int N;
ll P;
int main(){
    scanf("%lld%d",&P,&N);
    ll ret=0;
    for(int i=0;i<N;i++){
        ll v;
        scanf("%lld",&v);
        ret=(ret*P+v)%1000000007;
    }
    printf("%lld",ret);
}