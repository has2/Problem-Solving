#include <cstdio>

int T;
int main(){
    scanf("%d",&T);
    if(T%10) {
        puts("-1");
        return 0;
    }
    printf("%d ",T/300);
    T%=300;
    printf("%d ",T/60);
    T%=60;
    printf("%d ",T/10);
    T%=10;
}