#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstring>
using namespace std;
int M,N,board[200000],dp1[200000],dp2[200000],maxv[200000];
int sol(int r,int c){
    if(c>=N) return 0;
    int& ret = dp1[r*N+c];
    if(ret!=-1) return ret;
    return ret=board[r*N+c]+max(sol(r,c+2),sol(r,c+3));
}
int sol2(int r){
    if(r>=M) return 0;
    int& ret =dp2[r];
    if(ret!=-1) return ret;
    return ret=maxv[r]+max(sol2(r+2),sol2(r+3));
}
int main(){
    while(1){
        scanf("%d%d",&M,&N);
        if(N==0 && M==0) break;
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                int v;
                scanf("%d",&v);
                board[i*N+j]=v;
            }
            maxv[i] = max(sol(i,0),sol(i,1));
        }
        printf("%d\n",max(sol2(0),sol2(1)));
    }
}