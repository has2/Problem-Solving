#include <cstdio>
int N,a[1001],ans,l,r,mv;
int main(){
    scanf("%d",&N); 
    for(int i=0;i<N;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        a[u]=v;
        if(v>mv) mv=v;
    }
    int cur=0;
    for(int i=1;i<=1000;i++){
        if(a[i]==mv) {
            l=i;
            break;
        }
        if(a[i]>cur) cur=a[i];
        ans+=cur;
    }
    cur=0;
    for(int i=1000;i>=0;i--){
        if(a[i]==mv) {
            r=i;
            break;
        }
        if(a[i]>cur) cur=a[i];
        ans+=cur;
    }
    printf("%d",ans+mv*(r-l+1));
}