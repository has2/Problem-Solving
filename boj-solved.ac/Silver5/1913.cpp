#include <cstdio>
#include <algorithm>
using namespace std;
int N,M,K,map[2000][2000],ry,rx;
void check(int y,int x){
    if(M==K) ry=y,rx=x;
    map[y][x]=M--;
}
int main(){
    scanf("%d%d",&N,&K);
    M=N*N;
    for(int i=N,l=0;i>0;i-=2,l++){
        int y=l,x=l;
        for(int j=y;j<y+i;j++) check(j,x);
        y=y+i-1;
        for(int j=x+1;j<x+i;j++) check(y,j);
        x=x+i-1;
        for(int j=y-1;j>=l;j--) check(j,x);
        y=l;
        for(int j=x-1;j>l;j--) check(y,j);
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) printf("%d ",map[i][j]);
        puts("");
    }
    printf("%d %d\n",ry+1,rx+1);
}
