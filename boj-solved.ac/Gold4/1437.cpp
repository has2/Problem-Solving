#include <cstdio>
using namespace std;
int N,mod=10007;
int main(){
    scanf("%d",&N);
    if(N==0){
        puts("0");
        return 0;
    }

    int k = N/3;
    int m = N%3;
    int ret=1;
    if(m==1) {
        if(k>0) {
            k--;
            ret=4;
        }
    }else if(m==2){
        ret=2;
    }

    for(int i=0;i<k;i++) ret=(ret*3)%mod;
    printf("%d",ret); 
}