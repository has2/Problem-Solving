#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n,x,u=1e7,al,ar;
int main(){
    while(scanf("%d",&x) !=-1){
        bool ok = 0;
        al=ar=0;
        x*=u;
        scanf("%d",&n);
        vector<int> lego(n);
        for(int i=0;i<n;i++) scanf("%d",&lego[i]);
        sort(lego.begin(),lego.end());   
        for(int i=0;i<n;i++){
            int l = lego[i];
            auto it = lower_bound(lego.begin()+i+1,lego.end(),x-l);
            if(it != lego.end() && l+*it==x){
                if(!ok || ar-al < *it-l){
                    ok=1;
                    ar=*it;
                    al=l;
                }                
            }
        }
        if(ar==0) puts("danger");
        else printf("yes %d %d\n",al,ar);
    }
}