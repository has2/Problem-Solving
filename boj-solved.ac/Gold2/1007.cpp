#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int tc,N,x[20],y[20];
long long xsum[2],ysum[2];
double ans;
bool a[20];
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&N);
        for(int i=0;i<N;i++) scanf("%d%d",&x[i],&y[i]);
        memset(a,0,sizeof(a));
        for(int i=N/2;i<N;i++) a[i]=1;
        
        ans = -1;
        do{
            ysum[0]=ysum[1]=xsum[0]=xsum[1]=0;
            for(int i=0;i<N;i++) {
                xsum[a[i]]+=x[i];
                ysum[a[i]]+=y[i];
            }
            double tmp = sqrt((xsum[0]-xsum[1])*(xsum[0]-xsum[1])+(ysum[0]-ysum[1])*(ysum[0]-ysum[1]));
            if(ans < 0 || ans > tmp) ans = tmp;
        }while(next_permutation(a,a+N));
        printf("%f\n",ans);
    }
}
