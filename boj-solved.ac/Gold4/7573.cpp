// gold4 7573
#include <cstdio>
#include <algorithm>
using namespace std;
int N,L,M,ans;
pair<int,int> v[10000];
int main(){
    scanf("%d%d%d",&N,&L,&M);
    for(int i=0;i<M;i++) scanf("%d%d",&v[i].first,&v[i].second);
    sort(v,v+M);
    for(int h=1;h<L/2;h++){
        int w = L/2-h;
        if(w>N-1||h>N-1) continue;
        for(int i=0;i<M;i++){
            int y = v[i].first,x=v[i].second;
            for(int k=0;k<=w;k++){
                int cnt=1;
                for(int j=i+1;j<M;j++){
                    int ny = v[j].first, nx=v[j].second;
                    if(ny>y+h) break;
                    if(x-k<=nx&&nx<=x-k+w) cnt++;      
                }
                ans = max(ans,cnt);
            }
        }
    }
    printf("%d",ans);
}
