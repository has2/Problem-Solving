#include <cstdio>
int N,a[1001],d[1001],prev[1001];
void prt(int n){
    if(n==0) return;
    prt(prev[n]);
    printf("%d ",a[n]);
}
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++) scanf("%d",&a[i]);
    for(int i=1;i<=N;i++){
        for(int j=0;j<i;j++){
            if(a[j]<a[i]) {
                if(d[i]<d[j]+1){
                   d[i]=d[j]+1;
                   prev[i]=j;
                }
            }
        }
    }
    int mxi=0,mxV=0;
    for(int i=1;i<=N;i++) {
        if(d[i] > mxV){
            mxi=i;
            mxV=d[i];
        }
    }
    printf("%d\n",mxV);
    prt(mxi);
}

