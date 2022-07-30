#include <cstdio>
#include <cstring>
int w,h,dp[101][101][2][2];
int sol(int y,int x,int f,int d){
    if(y>h||x>w) return 0;
    if(y==h&&x==w) return 1;
    int& ret = dp[y][x][f][d];
    if(ret!=-1) return ret;
    if(d==0){
        ret=sol(y+1,x,0,0);
        if(!f) ret = (ret+sol(y,x+1,1,1))%100000;
    }else{
        ret=sol(y,x+1,0,1);
        if(!f) ret = (ret+sol(y+1,x,1,0))%100000;
    }
    return ret;
}
int main(){
    scanf("%d%d",&w,&h);
    memset(dp,-1,sizeof(dp));
    printf("%d",(sol(2,1,0,0)+sol(1,2,0,1))%100000);
}