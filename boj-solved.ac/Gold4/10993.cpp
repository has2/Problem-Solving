#include <algorithm>
#include <cstdio>
using namespace std;
bool map[2500][2500];
int N,eg[11];
void prt(int n,int sy,int sx){ 
    if(n==0) return;
    int h=eg[n],w=(h-1)*2+1,d=1,ey,ex=sx+w-1;
    if(n%2==0) {
        ey=sy+h-1;
    }else{
        d=-1;
        ey=sy-h+1;
    }
    for(int i=sx;i<=ex;i++) map[sy][i] = 1;
    int k=1;
    for(int y=sy+d;y!=ey+d;y+=d,k++){
        map[y][sx+k] = map[y][ex-k] = 1;
    }
    prt(n-1,(sy+ey)/2,sx+h/2+1);
}
int main(){
    scanf("%d",&N);
    eg[1]=1;
    for(int i=2;i<=N;i++) eg[i]=eg[i-1]*2+1;
    int k=0,d=1;
    if(N%2) prt(N,eg[N]-1,0);
    else {
        k=eg[N]-1,d=-1;
        prt(N,0,0);
    }

    for(int i=0;i<eg[N];i++){
        for(int j=0;j<eg[N]+k;j++) printf("%c",map[i][j] ? '*':' ');  
        k+=d;
        if(i<eg[N]-1) puts("");
    }
}