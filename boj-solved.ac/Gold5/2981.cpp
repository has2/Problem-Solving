#include <cstdio>
long long N;
int main(){
    scanf("%lld",&N);
    puts(N%7==2||N%7==0?"CY":"SK");
}

