#include <cstdio>
using namespace std;
int N,ans,a[1000001];
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        int v;
        scanf("%d",&v);
        if(a[v+1]){
            a[v+1]--;
            a[v]++;
        }else{
            ans++;
            a[v]++;
        }
    }
    printf("%d",ans);
}