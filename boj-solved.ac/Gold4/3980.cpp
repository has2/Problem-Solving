#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int tc,a[11][11],dp[11][1<<11],inf=-9e8;
int sol(int n,int msk){
    if(n==11) return 0;
    int& ret = dp[n][msk];
    if(ret!=-1) return ret;
    ret = inf;
    for(int i=0;i<11;i++){
        if(((1<<i)&msk)==0 && a[i][n]){
            ret = max(ret,sol(n+1,msk|(1<<i))+a[i][n]);
        }
    }
    return ret;
}
int main(){ 
    scanf("%d",&tc);
    while(tc--){
        for(int i=0;i<11;i++)
            for(int j=0;j<11;j++) scanf("%d",&a[i][j]);       
        memset(dp,-1,sizeof(dp));
        printf("%d\n",sol(0,0));
    }
}