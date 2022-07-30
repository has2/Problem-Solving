#include <cstdio>
int M,d,cur=1;
int main(){
    scanf("%d",&M);
    while(M--){
        int a,b,s;
        scanf("%d%d%d",&a,&b,&s);
        if(s==1) d=1-d;
        cur=cur*(double)b/a;
    }
    printf("%d %d",d,cur);
}