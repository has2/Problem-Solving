#include <cstdio>
using ll = long long;
ll mxT = 2e11;
int N,M,a[10000],ans;

int check(ll t){
    int ret = -1;
    ll lo = 0,hi;
    if(t>0){
        for(int i=0;i<M;i++){
            lo += (t-1)/a[i]+1;
        }
    }
    hi = lo;
    for(int i=0;i<M;i++){
        hi += t%a[i]==0;
        if(hi==N){
            ret = 0;
            ans = i;
            break;
        }
    }
    if(N <= lo) ret=-1;
    if(N > hi) ret=1;
    return ret;
}

int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++) scanf("%d",&a[i]);

    ll lo = -1, hi = mxT;
    while(lo+1<hi){
        ll mid = (lo+hi)/2;
        int c = check(mid);
        if(c==-1) hi = mid;
        else if(c==1) lo = mid;
        else{
            printf("%d",ans+1);
            return 0;
        }
    }
}