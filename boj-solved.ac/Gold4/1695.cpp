#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,a[5000],dp[5000][5000];

int sol(int l,int r){
    if(l>=r) return 0;
    int& ret = dp[l][r];
    if(ret !=-1) return ret;
    if(a[l]==a[r]) ret = sol(l+1,r-1);
    else ret = min(sol(l,r-1),sol(l+1,r))+1;
    return ret;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    memset(dp,-1,sizeof(dp));
    printf("%d",sol(0,n-1));
}