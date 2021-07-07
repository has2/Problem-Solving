#include <cstdio>
const int mxN=1e5+1;
int uf[mxN],G,P;
int find(int n){
    if(n==uf[n]) return n;
    return uf[n]=find(uf[n]);
}
int main(){
    scanf("%d%d",&G,&P);
    for(int i=1;i<=G;i++) uf[i]=i;
    int ans=0;
    for(int i=1;i<=P;i++){
        int v;
        scanf("%d",&v);
        int k = find(v);
        if(k==0) break;
        uf[k]=k-1;
        ans++;
    }
    printf("%d",ans);
}