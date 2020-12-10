#include <cstdio>
#include <algorithm>
int gcd(int a,int b){
    int c;
    while(b>0){
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}
int main(){
    int a,b,t;
    scanf("%d%d",&a,&b);
    if(a<b) std::swap(a,b);
    printf("%d\n",t=gcd(a,b));
    printf("%d\n",a*b/t);
}