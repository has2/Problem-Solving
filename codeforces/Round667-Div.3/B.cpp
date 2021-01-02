// #667 div3 B
#include <cstdio>
#include <algorithm>
using namespace std;
using ll = long long;
int tc; 
ll a,b,x,y,n,ret;
ll sol(){
    ll ans,tn;
    if(a-x>=n){
        ans = (a-n)*b;
    }else{
        tn = n-(a-x);
        ans = x*max(y,b-tn);
    }
    return ans;
}
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d%d%d%d",&a,&b,&x,&y,&n);
        ret = sol();
        swap(a,b);
        swap(x,y);
        ret = min(ret,sol());
        printf("%lld\n",ret);
    }
}
