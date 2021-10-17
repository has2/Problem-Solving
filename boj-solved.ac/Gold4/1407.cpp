#include <cstdio>
#include <vector>
using namespace std;
using ll = long long;
ll A,B;
ll bsearch(ll v,ll lo,ll hi,ll c,bool left){
    while(lo+1<hi){
        ll mid = (lo+hi)/2;
        if(v*mid>c) hi=mid;
        else if(v*mid<=c) lo=mid;
    }
    if(left){
        if(lo*v<c) lo++;
    }else{
        if(lo*v>c) lo--;
    }
    return lo;
}
int main(){
    scanf("%lld%lld",&A,&B);

    vector<ll> vec;
    for(ll i=2;;i*=2){
       if(i>B) break;
       vec.push_back(i);
    }
    ll ans=0,acnt=0;
    for(int i=vec.size()-1;i>=0;i--){
        ll v = vec[i];
        ll lo=1,hi=(1e15+2)/v;
        ll left = bsearch(v,lo,hi,A,1);
        ll right = bsearch(v,lo,hi,B,0);
        if(left<=right && v*left>=A && v*right<=B) {
            ll cur = right-left+1-acnt;
            acnt+=cur;
            ans+=cur*v;
        }
    }
    printf("%lld",ans+(B-A+1-acnt));
}