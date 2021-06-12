#include <cstdio>
#include <algorithm>
using namespace std;
int N,M;
int gcd(int a,int b){
    if(a>b) swap(a,b);
    while(a>0){
        int c = b%a;
        b=a;
        a=c;
    }
    return b;
}
int main(){
    scanf("%d%d",&N,&M);
    printf("%d",M-gcd(N,M));
}