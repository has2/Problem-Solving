#include <cstdio>
#include <map>
using namespace std;
using ll = long long;
ll N;
map<ll,ll> m;
int P,Q;
ll sol(ll n){
    if(n==0) return 1;
    if(m.find(n) != m.end()) return m[n];
    return m[n] = sol(n/P)+sol(n/Q);
}
int main(){
    scanf("%lld%d%d",&N,&P,&Q);
    printf("%lld",sol(N));
}