#include <cstdio>
#include <algorithm>
using namespace std;
int N,M,board[201][201],ans=-9e8;
int sol(int h,int w){
    int ret=-9e8;
    for(int i=1;i<=N-h+1;i++)
        for(int j=1;j<=M-w+1;j++)
            ret=max(ret,board[i+h-1][j+w-1] - board[i-1][j+w-1] - board[i+h-1][j-1] + board[i-1][j-1]);
    return ret;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            scanf("%d",&board[i][j]);
            board[i][j]+=board[i][j-1]+board[i-1][j]-board[i-1][j-1];
        }
    }
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            ans=max(ans,sol(i,j));
    printf("%d",ans);
}