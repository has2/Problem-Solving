#include <cstdio>
int N,C,cy,cx;
int main(){
    scanf("%d%d",&N,&C);
    cy=N,cx=N;
    while(C--){
        int y,x;
        scanf("%d%d",&y,&x);
        if(y>cy||x>cx) continue;
        int ny=y,nx=cx,w=y*cx;
        if(w<cy*x){
            ny=cy,nx=x;
        }
        cy=ny,cx=nx;
    }
    printf("%d",cy*cx);
}