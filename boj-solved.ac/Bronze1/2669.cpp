#include <cstdio>
int a,b,c,d,board[101][101],ans;
int main(){
    for(int i=0;i<4;i++){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        for(int i=a;i<c;i++)
            for(int j=b;j<d;j++) board[i][j]=1;
    }
    for(int i=0;i<=100;i++)
        for(int j=1;j<=100;j++) ans+=board[i][j];
    printf("%d",ans);
}