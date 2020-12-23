#include <cstdio>
long long S,sum;
int main(){
    scanf("%lld",&S);
    for(int i=1;;i++){
        sum+=i;
        if(sum>S) {
            printf("%d",i-1);
            break;
        }
    }
}