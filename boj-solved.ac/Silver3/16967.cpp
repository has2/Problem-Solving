#include <cstdio>
int H,W,X,Y,B[700][700],A[300][300];
int main(){
    scanf("%d%d%d%d",&H,&W,&X,&Y);
    for(int i=0;i<H+X;i++)
        for(int j=0;j<W+Y;j++) scanf("%d",&B[i][j]);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(i>=X && j>=Y) A[i][j] = B[i][j] - A[i-X][j-Y];
            else A[i][j] = B[i][j];
            printf("%d ",A[i][j]);
        }
        puts("");
    }
}