#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;
int tc;
ll x;
 
bool solve(){
 
    ll a = min(10000LL,(ll)sqrt(x));
 
    for(ll i=1;i<=a;i++){
 
 
        ll lo=0,hi=a+1;
        while(lo+1<hi){
 
            ll mid = (lo+hi)/2;
            
            ll v = i*i*i+mid*mid*mid;
            if(v==x) return true;
            if(v>x) hi = mid;
            else lo = mid;
 
        }
        //printf("i:%d, lo:%lld\n",i,lo);
    }
    return false;
}
 
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%lld",&x);
 
        if(solve()) puts("YES");
        else puts("NO");
    }
 
}