#include <cstdio>
#include <algorithm>
using namespace std;
int N;
pair<int,int> a[2000001];
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        int s,e;
        scanf("%d%d",&s,&e);
        a[i]={s,1};
        a[i+N]={e,-1};
    }
    sort(a,a+2*N);
    int ans=0,cnt=0;
    for(int i=0;i<2*N;i++){
        cnt+=a[i].second;
        ans=max(cnt,ans);
    }
    printf("%d",ans);
}