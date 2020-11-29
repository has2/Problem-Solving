#include <cstdio>
#include <algorithm>
using namespace std;
int N,M,K,org[51][51],cp[51][51],tmp[51][51],r[6],c[6],s[6],v[6],inf=1e8;
int sol(){
    int ret = inf;
    for(int i=0;i<K;i++){
        int ll = 2*s[v[i]]+1, yy = r[v[i]]-s[v[i]], xx = c[v[i]]-s[v[i]];        
        int l = ll, y = yy, x = xx;
        while(l>0){
            if(l==1) {
                tmp[y][x] = cp[y][x];
                break;
            }
            for(int j=x+1;j<x+l;j++) tmp[y][j] = cp[y][j-1];
            for(int j=y+1;j<y+l;j++) tmp[j][x+l-1] = cp[j-1][x+l-1];
            for(int j=x;j<x+l-1;j++) tmp[y+l-1][j] = cp[y+l-1][j+1];
            for(int j=y;j<y+l-1;j++) tmp[j][x] = cp[j+1][x];
            y++,x++;
            l-=2;
        }
        for(int j=yy;j<yy+ll;j++)
            for(int k=xx;k<xx+ll;k++) cp[j][k] = tmp[j][k];
    }
    for(int i=1;i<=N;i++){
        int sum = 0;
        for(int j=1;j<=M;j++) sum+=cp[i][j];
        ret = min(ret,sum);
    }
    return ret;
}
int main(){
    scanf("%d%d%d",&N,&M,&K);
    for(int i=1;i<=N;i++) 
        for(int j=1;j<=M;j++) scanf("%d",&org[i][j]);

    for(int i=0;i<K;i++) {
        scanf("%d%d%d",&r[i],&c[i],&s[i]);
        v[i] = i;
    }
    int ans = inf;
    do{
        for(int i=1;i<=N;i++) copy(org[i],org[i]+M+1,cp[i]);
        ans =min(ans,sol());
    }while(next_permutation(v,v+K));
    printf("%d",ans);
}