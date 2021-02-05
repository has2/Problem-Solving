#include <cstdio>
using ll = long long;
ll X,K,ret;
int main(){
    scanf("%lld%lld",&X,&K);
    int j=0;
    for(int i=0;;i++){
        if(!((X>>i)&1)){
            ret |= ((K>>j)&1) << i;
            j++;
            if(!(K>>j)) break;
        }
    }   
    printf("%lld",ret);
}
