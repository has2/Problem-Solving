#include <cstdio>
#include <cstring>
using namespace std;
int N,a[16][16],dp[16][16][3];
bool check(int y,int x){
    return y>=0&&x>=0&&y<N&&x<N&&!a[y][x];
}
bool all(int y,int x){
    return check(y,x+1) && check(y+1,x) && check(y+1,x+1);
}
int sol(int y,int x,int k){
    if(y==N-1&&x==N-1) return 1;
    int& ret = dp[y][x][k];
    if(ret!=-1) return ret;
    ret = 0;
    if(k==0){
        if(check(y,x+1)) ret+=sol(y,x+1,0);
    }else if(k==1){
        if(check(y+1,x)) ret+=sol(y+1,x,1);
    }else{
        if(check(y,x+1)) ret+=sol(y,x+1,0);
        if(check(y+1,x)) ret+=sol(y+1,x,1);
    }
    if(all(y,x)) ret+=sol(y+1,x+1,2);
    return ret;
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) scanf("%d",&a[i][j]);
    memset(dp,-1,sizeof(dp));
    printf("%d",sol(0,1,0));
}