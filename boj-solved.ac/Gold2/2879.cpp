#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int N,a[1001];
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    for(int i=0;i<N;i++) {
        int v;
        scanf("%d",&v);
        a[i]-=v;
    }
    int ans=0;
    bool ok=1;
    while(ok){
        ok=0;
        for(int i=0;i<N;i++){
            if(!a[i]) continue;
            ok=1;
            int minv=a[i];
            for(int j=i+1;j<=N;j++){
                if(a[i]*a[j]>0){
                    if(abs(a[j])<abs(minv)){
                        minv=a[j];
                    }
                }else{
                    ans+=abs(minv);
                    for(int k=i;k<j;k++) a[k]-=minv;     
                    i=j-1;
                    break;
                }
            }
        }
    }
    printf("%d",ans);
}