#include <cstdio>
int v,a[10];
int main(){
    while(scanf("%1d",&v)!=-1) a[v]++;
    int m = a[6]+a[9];
    a[6]=a[9]=m/2+m%2;
    v=0;
    for(int i=0;i<10;i++)if(v<a[i]) v=a[i];
    printf("%d",v);
}