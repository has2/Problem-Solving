#include <cstdio>
int N,a[30],b[30];
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);

    int idx=0;
    b[0]=a[0];
    for(int j=1;j<N;j++){
        int mv = b[idx];
        idx=(idx+mv)%N;
        while(b[idx]!=0) idx=(idx+1)%N;
        b[idx]=a[j];
    }
    printf("%d\n",N);
    for(int i=0;i<N;i++) printf("%d ",b[i]);
}