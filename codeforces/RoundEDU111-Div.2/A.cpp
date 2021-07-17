#include <cstdio>
int tc,n;
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        int k=0;
        while(k*k<n) k++;   
        printf("%d\n",k);
    }   
}