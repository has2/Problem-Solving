#include <string>
#include <cstdio>
using namespace std;
int tc,n,k,a[200000];
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&k);
        int fi=n;
        for(int i=0;i<n;i++) {
            scanf("%1d",&a[i]);
            if(a[i]==1 && fi==n) fi=i;
        }
        int cnt=fi/(k+1);
        if(fi==n) {
            cnt=1+(n-1)/(k+1);
        };
        for(int i=fi;i<n;){
            int ok=1;
            int j;
            for(j=i+1;j<=i+k&&j<n;j++) {
                if(a[j]) {
                    ok=0;
                    break;
                }
            }
            cnt+=ok&&!a[i];
            i=j;
        }
        printf("%d\n",cnt);
    }
}
