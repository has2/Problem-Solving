#include <cstdio>
using ll = long long;
ll A,B,C;
ll sol(ll n){
    if(n==1) return A; 
    ll ret = sol(n/2);
    ret = (ret*ret)%C;
    if(n%2) ret=(ret*A)%C;
    return ret;
}
int main(){
    scanf("%lld%lld%lld",&A,&B,&C);
    printf("%lld",sol(B)%C);
}