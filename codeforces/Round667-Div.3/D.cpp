#include <cstdio>
using namespace std;
using ll = long long;
int tc,s;
ll n,tn;
int sum(){
    int ret=0;
    ll tt=tn;
    while(tt>0){
        ret+=(tt%10);
        tt/=10;
    }
    return ret;
}
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%lld%d",&n,&s);
        ll k = 10;
        tn=n;
        while(sum()>s){
            ll r = tn%k;
            if(r!=0) tn+=k-r;
            k*=10;
        }
        printf("%lld\n",tn-n);
    }
}
