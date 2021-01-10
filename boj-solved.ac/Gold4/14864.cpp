#include <cstdio>
int N,M,a[100001],exist[100001];
int main(){
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++) a[i]=i;
    while(M--){
        int u,v;
        scanf("%d%d",&u,&v);
        a[u]++,a[v]--;
    }
    for(int i=1;i<=N;i++) {
        if(exist[a[i]]){
            puts("-1");
            return 0;
        }
        exist[a[i]]=1;
    }
    for(int i=1;i<=N;i++) printf("%d ",a[i]);
}
