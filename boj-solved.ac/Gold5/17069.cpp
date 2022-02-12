#include <cstdio>
#include <cstring>
using namespace std;
using ll = long long;
int N,board[35][35];
ll dp[35][35][3];
ll sol(int r,int c,int k){
    if(r==N&&c==N) return 1;
    ll& ret = dp[r][c][k];
    if(ret!=-1) return ret;
    ret=0;
    if(k==0){
        if(!board[r][c+1]) {
            ret+=sol(r,c+1,0);
            if(!board[r+1][c+1] && !board[r+1][c]) ret+=sol(r+1,c+1,2);
        }
    }
    if(k==1){
        if(!board[r+1][c]) {
            ret+=sol(r+1,c,1);
            if(!board[r+1][c+1] && !board[r][c+1]) ret+=sol(r+1,c+1,2);
        }
    }
    if(k==2){
        if(!board[r][c+1]) ret+=sol(r,c+1,0);
        if(!board[r+1][c]) ret+=sol(r+1,c,1);
        if(!board[r+1][c+1] && !board[r+1][c] && !board[r][c+1]) ret+=sol(r+1,c+1,2);        
    }
    return ret;
}
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++) 
            scanf("%d",&board[i][j]);
    for(int i=1;i<=N+1;i++) board[N+1][i]=board[i][N+1]=1;
    memset(dp,-1,sizeof(dp));
    printf("%lld",sol(1,2,0));
}