#include <cstdio>
using namespace std;
int N,ans,cur,a[100000];
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    for(int i=N-1;i>=0;i--) {
        if(a[i]>cur){
            cur=a[i];
            ans++;
        }
    }
    printf("%d",ans);
}