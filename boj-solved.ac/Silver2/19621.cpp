#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N,a[26],b[26],c[26],ans,check[26];
void sol(int n){
    if(n==N) {
        int prev=-2,sum=0;
        bool ok=1;
        for(int i=0;i<N;i++){
            if(check[i]){
                if(i-prev==1) {
                    ok=0;
                    break;
                }else{
                    prev=i;
                    sum+=c[i];
                }
            }
        }
        if(ok) ans=max(ans,sum);
        return;
    }
    check[n]=1;
    sol(n+1);
    check[n]=0;
    sol(n+1);
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
    sol(0);
    printf("%d",ans);
}