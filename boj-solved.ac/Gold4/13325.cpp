#include <cstdio>
int k,last,a[1<<21];
long long ans;
int sol(int n){
    if((1<<k)-1 <= n && n < last) return 0;
    int l = sol(n*2+1),r = sol(n*2+2);
    if(a[n*2+1]+l<a[n*2+2]+r) a[n*2+1] = a[n*2+2]+r-l;
    else a[n*2+2] = a[n*2+1]+l-r;
    ans += a[n*2+2]+a[n*2+1];
    return l+a[n*2+1];
}
int main(){
    scanf("%d",&k);
    last = (1<<(k+1))-1;
    for(int i=1;i<last;i++) scanf("%d",&a[i]);
    sol(0);
    printf("%lld",ans);
}