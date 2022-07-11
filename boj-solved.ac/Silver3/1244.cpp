#include <cstdio>
int N,a[101],k;

void sol1(int n){
    for(int i=n;i<=N;i+=n){
        a[i]=1-a[i];
    }
}
void sol2(int n){
    int k=0;
    for(int i=1;i<=N/2;i++){
        if(n-i<1||n+i>N||a[n-i]!=a[n+i]) break;
        k=i;
    }
    for(int i=n-k;i<=n+k;i++){
        a[i]=1-a[i];
    }
}

int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++) scanf("%d",&a[i]);
    scanf("%d",&k);
    while(k--){
        int p,m;
        scanf("%d%d",&p,&m);
        if(p==1){
            sol1(m);
        }else{
            sol2(m);
        }
    }
    for(int i=1;i<=N;i++){
        printf("%d ",a[i]);
        if(i%20==0) puts("");
    }
}
