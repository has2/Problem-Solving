#include <cstdio>
int N,a,b,ans;
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d%d",&a,&b);
        ans+=b%a;
    }
    printf("%d",ans);
}