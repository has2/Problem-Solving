#include <cstdio>
#include <algorithm>
using namespace std;
int L,P,V,n;
int main(){
    while(1){
        scanf("%d%d%d",&L,&P,&V);
        if(L==0) break;
        printf("Case %d: %d\n",++n,(V/P)*L+min(V%P,L));
    }
}
