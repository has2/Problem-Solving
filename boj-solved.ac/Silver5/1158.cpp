#include <cstdio>
int n,k,p,e;
bool check[5001];
int main(){
    scanf("%d%d",&n,&k);
    int cnt = 0;
    printf("<");
    while(1){
        if(cnt==k) {
            e++;
            check[p]=1;
            printf("%d",p);
            if(e<n) printf(", ");
            else puts(">");
            cnt = 0;
            if(e==n) break;
            
        }
        if(p==n) p=0; 
        if(!check[++p]) cnt++;
    }   
}