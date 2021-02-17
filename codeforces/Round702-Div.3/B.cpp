#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int tc,n,a[50];
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        int ans = 0;
        for(int i=1;i<n;i++){
            int p=a[i-1],q=a[i];
            if(p>q) swap(p,q);
            if(2*p>=q) continue;
            int cur=p;
 
            for(int cur=2*p;cur<q;cur*=2){
                ans++;
            }  
        }
        printf("%d\n",ans);
    }
}