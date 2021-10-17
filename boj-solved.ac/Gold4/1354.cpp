#include <cstdio>
#include <map>
using namespace std;
using ll = long long;
ll N,P,Q,X,Y;
map<ll,ll> dp;
ll sol(ll n){
    if(n<=0) return 1;
    if(dp.find(n)!=dp.end()) return dp[n];
    return dp[n] = sol(n/P-X)+sol(n/Q-Y);
}
int main(){
    scanf("%lld%lld%lld%lld%lld",&N,&P,&Q,&X,&Y);
    printf("%lld",sol(N));
}