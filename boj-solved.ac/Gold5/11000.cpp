#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N,ans;
pair<int,int> a[400001];
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int s,e;
        scanf("%d%d",&s,&e);
        a[i]={s+1,-1};
        a[i+N]={e,1};
    }
    sort(a,a+2*N);

    int cnt=0;
    for(int i=0;i<2*N;i++){
        cnt-=a[i].second;
        ans=max(cnt,ans);
    }
    printf("%d",ans);
}