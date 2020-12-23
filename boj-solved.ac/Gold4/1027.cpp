#include <cstdio>
int N,a[50],ans,c[50];
double getD(int i,int j){
    return (a[j]-a[i])/(double)(j-i);
}
int main(){ 
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    for(int i=0;i<N-1;i++){
        double cur,d;
        for(int j=i+1;j<N;j++){
            d = getD(i,j);
            if(j-1==i || cur < d){
                cur = d;
                c[i]++; c[j]++;
            }
        }
    }
    for(int i=0;i<N;i++) if(ans < c[i]) ans=c[i];
    printf("%d",ans);
}