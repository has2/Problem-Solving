//gol3 16434
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int N;
ll att,curH,need,tt[123457],aa[123457],hh[123457],p[123457];
int main(){
    scanf("%d%d",&N,&att);
    for(int i=0;i<N;i++){
        ll t,a,h;
        scanf("%lld%lld%lld",&t,&a,&h);
        if(t==1){
            ll cnt = h/att;
            if(h%att) cnt++;
            p[i] = (cnt-1)*a;
            need = max(need,p[i]+1);
        }else att+=a; 
        tt[i] = t, aa[i] = a, hh[i] = h;
    }
    ll curH = need;
    for(int i=0;i<N;i++){
        ll t=tt[i],a=aa[i],h=hh[i];
        if(t==1){
            if(curH-p[i] <= 0){
                need+= p[i]-curH+1;
                curH+= p[i]-curH+1;
            }
            curH-=p[i];
        }else {
            curH+=h;
            if(curH > need) curH=need;
        }
    }
    printf("%lld",need);
}