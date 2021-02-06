#include <cstdio>
using namespace std;
int N,M,uf[500000];
int find(int a){
    if(uf[a]==a) return a;
    return uf[a] = find(uf[a]);
}
bool merge(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b) return 0;
    uf[a]=b;
    return 1;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++) uf[i]=i;
    for(int i=1;i<=M;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        if(!merge(u,v)){
            printf("%d",i);
            return 0;
        }
    }
    puts("0");
}