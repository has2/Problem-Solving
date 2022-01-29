#include <cstdio>
#include <algorithm>
using namespace std;
using ll = long long;
int N,M;
ll a[50][50];
ll sol(int sy,int sx,int ey,int ex){
    ll sum=0;
    for(int i=sx;i<=ex;i++)
        for(int j=sy;j<=ey;j++)
            sum+=a[j][i];
    return sum;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++) scanf("%1lld",&a[i][j]);
        
    ll ans=0;
    for(int i=0;i<N-2;i++)
        for(int j=i+1;j<N-1;j++)
            ans=max(ans,sol(0,0,i,M-1)*sol(i+1,0,j,M-1)*sol(j+1,0,N-1,M-1));

    for(int i=0;i<M-2;i++)
        for(int j=i+1;j<M-1;j++)
            ans=max(ans,sol(0,0,N-1,i)*sol(0,i+1,N-1,j)*sol(0,j+1,N-1,M-1));

    for(int i=0;i<N-1;i++){
        for(int j=0;j<M-1;j++) ans=max(ans,sol(0,0,i,M-1)*sol(i+1,0,N-1,j)*sol(i+1,j+1,N-1,M-1));
        for(int j=0;j<M-1;j++) ans=max(ans,sol(i+1,0,N-1,M-1)*sol(0,0,i,j)*sol(0,j+1,i,M-1));
    }
    for(int i=0;i<M-1;i++){
        for(int j=0;j<N-1;j++) ans=max(ans,sol(0,0,N-1,i)*sol(0,i+1,j,M-1)*sol(j+1,i+1,N-1,M-1));
        for(int j=0;j<N-1;j++) ans=max(ans,sol(0,i+1,N-1,M-1)*sol(0,0,j,i)*sol(j+1,0,N-1,i));
    }
    printf("%lld",ans);
}