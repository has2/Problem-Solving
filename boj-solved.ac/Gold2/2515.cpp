#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N,S,dp[300000],h[300000];
pair<int,int> a[300000];
int sol(int n){
    if(n>=N) return 0;
    int& ret=dp[n];
    if(ret!=-1) return ret;

    int p = a[n].first+S;
    int k = lower_bound(h,h+N,p)-h;
    ret=sol(n+1);
    ret=max(ret,a[n].second+sol(k));

    return ret;
}
int main(){
    scanf("%d%d",&N,&S);
    for(int i=0;i<N;i++) {
        scanf("%d%d",&a[i].first,&a[i].second);
        h[i]=a[i].first;
    }
    sort(h,h+N);
    sort(a,a+N);
    memset(dp,-1,sizeof(dp));
    printf("%d",sol(0));
}