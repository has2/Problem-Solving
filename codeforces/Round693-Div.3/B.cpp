#include <cstdio>
#include <cstring>
int tc,N,a[3],dp[101][101];
int sol(int n1,int n2){
    int& ret=dp[n1][n2];
    if(ret!=-1) return ret;
    if(n1==0&&n2==0) return ret=1;
    
    if(n1-2>=0 && sol(n1-2,n2)) return ret=1;
    if(n1-2>=0 && n2-1>=0 && sol(n1-2,n2-1)) return ret=1;
    if(n2-2>=0 && sol(n1,n2-2)) return ret=1;
    return ret=0;
}
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&N);
        a[1]=a[2]=0;
        while(N--){
            int v;
            scanf("%d",&v);
            a[v]++;
        }
        memset(dp,-1,sizeof(dp));
        if(sol(a[1],a[2])) puts("YES");
        else puts("NO");
    }
}
