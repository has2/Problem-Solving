#include <cstdio>
#include <iostream>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
using ll = long long;
string s;
int tc,N,a[200001];
ll sump[200001],summ[200001];
 
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&N);
        memset(sump,0,sizeof(sump));
        memset(summ,0,sizeof(summ));
        for(int i=1;i<=N;i++) {
            int v;
            scanf("%d",&v);
            a[i]=v-i;
        }
        ll ans=0;
        for(int i=1;i<=N;i++){
            if(a[i]>=0) {
                ans+=sump[a[i]]++;
            }else{
                ans+=summ[-a[i]]++;
            }
        }
        printf("%lld\n",ans);
    }
}