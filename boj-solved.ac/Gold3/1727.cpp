#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m,a[1000],b[1000],dp[1000][1000],INF=1e7;
int sol(int p,int q){
    if(p==n) return 0;
    if(q==m) return INF;
    int& ret = dp[p][q];
    if(ret !=-1) return ret;
    ret = INF;
    ret = min(ret,sol(p,q+1));
    ret = min(ret,abs(a[p]-b[q])+sol(p+1,q+1));
    return ret;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<m;i++) scanf("%d",&b[i]);
    if(n>m) {
        swap(n,m);
        swap(a,b);
    }
    sort(a,a+n);
    sort(b,b+m);

    memset(dp,-1,sizeof(dp));
    printf("%d",sol(0,0));
}