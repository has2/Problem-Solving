#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int M,N,L,p[100000],ans;
pair<int,int> ani[100000];
int main(){
    scanf("%d%d%d",&M,&N,&L);
    for(int i=0;i<M;i++) scanf("%d",&p[i]);
    for(int i=0;i<N;i++) scanf("%d%d",&ani[i].first,&ani[i].second);
    sort(p,p+M);
    sort(ani,ani+N);
    int j=0;
    for(int i=0;i<M;i++){
        for(;j<N;j++){
            if(i<M-1&& abs(ani[j].first-p[i]) > abs(ani[j].first-p[i+1])) break;
            if(abs(ani[j].first-p[i])+ani[j].second <= L) ans++;
        }
    }
    printf("%d",ans);
}