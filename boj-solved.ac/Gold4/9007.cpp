#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int tc,K,N,a[4][1000],b[2][1000000];
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&K,&N);
        for(int j=0;j<4;j++)
         for(int i=0;i<N;i++) scanf("%d",&a[j][i]);
        int idx=0;
        for(int j=0;j<N;j++)
            for(int k=0;k<N;k++) {
                b[0][idx]=a[0][j]+a[1][k];
                b[1][idx]=a[2][j]+a[3][k];
                idx++;
            }
 
        sort(b[0],b[0]+N*N);
        sort(b[1],b[1]+N*N);
        int p=4e7,ans=4e7;
        for(int i=0;i<N*N;i++){
            int t=K-b[0][i];
            int j = lower_bound(b[1],b[1]+N*N,t)-b[1];
            int v,ab;
            
            if(j<N*N){
                v=b[1][j];
                if(j>0 && t-b[1][j-1] <= v-t){
                    v=b[1][j-1];
                }
            }else{
                v=b[1][j-1];
            }
            ab=abs(t-v);
            if(ab <= p){
                if(ab < p || ans > b[0][i]+v){
                    p=ab;
                    ans=b[0][i]+v;
                }
            }
        }
        printf("%d\n",ans);
    }
}
