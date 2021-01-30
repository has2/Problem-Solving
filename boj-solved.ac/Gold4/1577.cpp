#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
using ll = long long;
int dy[2]={1,0},dx[2]={0,1};
int K,N,M,map[101][101][2];
ll dp[101][101];
ll sol(int y,int x){
    if(y==N&&x==M) return 1;
    ll& ret = dp[y][x];
    if(ret!=-1) return ret;
    ret = 0;
    for(int i=0;i<2;i++){
        if(!map[y][x][i]){
            int ny=y+dy[i],nx=x+dx[i];
            if(ny<=N&&nx<=M) ret+=sol(ny,nx);
        }
    }
    return ret;
}
int main(){
    scanf("%d%d%d",&N,&M,&K);
    while(K--){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(a>c)swap(a,c);
        else if(b>d)swap(b,d);
        if(a<c) map[a][b][0]=1;
        else if(b<d) map[a][b][1]=1;
    }
    memset(dp,-1,sizeof(dp));
    printf("%lld",sol(0,0));
}