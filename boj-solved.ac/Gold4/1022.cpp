#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int r1,r2,c1,c2;

int getV(int r,int c){

    int a = max(abs(r),abs(c));
    int v = (2*a+1);
    v*=v;
    if(a==r) return v-(a-c);
    v-=2*a;
    if(-a==c) return v-(a-r);
    v-=2*a;
    if(-a==r) return v-(a+c);
    v-=2*a;
    return v-(a+r);
}
int main(){
    scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
    int k = 0;
    for(int i=r1;i<=r2;i++){
        for(int j=c1;j<=c2;j++){
            int v = getV(i,j);
            k = max(v,k);
        }
    }

    int t = 0;
    while(k>0){
        t++;
        k/=10;
    }
    for(int i=r1;i<=r2;i++){
        for(int j=c1;j<=c2;j++){
            printf("%*d ",t,getV(i,j));
        }
        puts("");
    }
}