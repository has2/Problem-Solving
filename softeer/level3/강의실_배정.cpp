#include <cstdio>
#include <algorithm>
using namespace std;
pair<int,int> a[1000000];
int N,ans;
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d%d",&a[i].second,&a[i].first);
    sort(a,a+N);
    for(int i=0;i<N;i++){
        int end = a[i].first;
        ans++;
        bool ok=0;
        for(int j=i+1;j<N;j++){
            if(end<=a[j].second){
                i=j-1;
                ok=1;
                break;
            }
        }
        if(!ok) break;
    }
    printf("%d",ans);
}