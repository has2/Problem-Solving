#include <cstdio>
typedef long long ll;
ll G;
int main(){
    scanf("%lld",&G);
    ll s = 1,e=1;
    bool ok = 0;
    while(!(e-s == 1 && e*e-s*s > G)){
        ll t  = e*e-s*s;
        if(t <= G) e++;
        else if(t > G) s++;
        if(t == G){
            ok = 1;
            printf("%lld\n",e-1);
        }
    }
    if(!ok) puts("-1");
}