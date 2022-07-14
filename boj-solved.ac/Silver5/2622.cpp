#include <cstdio>
int N,ans;
int main(){
    scanf("%d",&N);
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j++){
            int k=N-i-j;
            if(j>k) break;
            if(i+j>k) ans++;
        }
    }
    printf("%d",ans);
}