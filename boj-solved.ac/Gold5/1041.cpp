#include <cstdio>
#include <algorithm>
using namespace std;
using ll = long long;
ll N,a[6];
int main(){
    ll p=200,q=200,r=200;
    scanf("%lld",&N);
    for(int i=0;i<6;i++) {
        scanf("%lld",&a[i]);
        r=min(r,a[i]);
    }
    if(N==1) {
        int sum=0,m=0;
        for(int i=0;i<6;i++){
            sum+=a[i];
            m=max(m,(int)a[i]);
        }
        printf("%d",sum-m);
        return 0;
    }
    p=min(p,a[0]+a[1]+a[2]);
    p=min(p,a[0]+a[3]+a[4]);
    p=min(p,a[0]+a[1]+a[3]);
    p=min(p,a[0]+a[2]+a[4]);
    p=min(p,a[5]+a[3]+a[4]);
    p=min(p,a[5]+a[1]+a[3]);
    p=min(p,a[5]+a[1]+a[2]);
    p=min(p,a[5]+a[2]+a[4]);
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(i!=j && i+j!=5) q=min(q,a[i]+a[j]);
        }
    }
    ll ans = 4*p+4*q+8*(N-2)*q+4*(N-2)*r+5*(N-2)*(N-2)*r;
    printf("%lld",ans);
}