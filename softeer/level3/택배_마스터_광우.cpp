#include <cstdio>
#include <algorithm>
using namespace std;
int N,M,K,a[10],ans=9e8;
int main(){
    scanf("%d%d%d",&N,&M,&K);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    sort(a,a+N);
    do{
        int cur=0, work=0;
        for(int i=0;i<K;i++){
            int r = M;
            while(1){
                r-=a[cur];
                if(r<0) break;
                work+=a[cur++];
                cur%=N;
            }
        }
        ans=min(ans,work);
    }while(next_permutation(a,a+N));
    printf("%d",ans);
}