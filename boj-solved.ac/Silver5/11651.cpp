#include <cstdio>
#include <algorithm>
using namespace std;
int N;
pair<int,int> a[100000];
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d%d",&a[i].second,&a[i].first);
    sort(a,a+N);
    for(int i=0;i<N;i++) printf("%d %d\n",a[i].second,a[i].first);
}