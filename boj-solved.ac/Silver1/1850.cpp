#include <cstdio>
#include <algorithm>
using namespace std;
using ll = long long;
ll a,b;
ll gcd(ll a,ll b){
    if(b>a) swap(a,b);
    while(b!=0){
        ll c = a%b;
        a=b;
        b=c;
    }
    return a;
}
int main(){
    scanf("%lld%lld",&a,&b);
    for(int i=0;i<gcd(a,b);i++) printf("1");
}