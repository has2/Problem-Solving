#include <cstdio>
using namespace std;
int N,K,ans;
int main(){
    scanf("%d%d",&N,&K);
    int sum=K*(K+1)/2;
    if(sum>N){
        puts("-1");
        return 0;
    }
    int a = N-sum;
    if(a%K) printf("%d",K);
    else printf("%d",K-1);
}