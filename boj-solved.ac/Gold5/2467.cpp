#include <cstdio>
#include <cmath>
using namespace std;
int N,a[100000];
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    int l=0,r=N-1,ans=2e9+1;
    int al=l,ar=r;
    while(l<r){
        int v = a[l]+a[r];
        if(abs(v)<ans){
            al=l;
            ar=r;
            ans=abs(v);
        }
        if(v==0) break;
        else if(v>0) r--;
        else l++;
    }
    printf("%d %d",a[al],a[ar]);
}