#include <cstdio>
#include <algorithm>
using namespace std;
int tc,M,N,x,y;
int gcd(int a,int b){
    if(a>b) swap(a,b);
    while(a!=0){
        int c = b%a;
        b=a;
        a=c;
    }
    return b;
}
int sol(){
    int lcm = (M*N)/gcd(M,N);
    int mxM = lcm/M, mxN = lcm/N;
    int curM=0,curN=0;
    while(curM<mxM&&curN<mxN){
        int l = curM*M+x;
        int r = curN*N+y;
        if(l==r) return l;
        if(l>r) curN++;
        else curM++;
    }
    return -1;
}
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d%d%d",&M,&N,&x,&y);
        printf("%d\n",sol());
    }
}