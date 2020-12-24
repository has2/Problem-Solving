#include <cstdio>
#include <algorithm>
using namespace std;
pair<int,int> a[8];
int main(){ 
    for(int i=0;i<8;i++) {
        scanf("%d",&a[i].first);
        a[i].second=i+1;
    }
    sort(a,a+8);
    int sum=0;
    for(int i=0;i<5;i++){
        sum+=a[i+3].first;
        a[i].first=a[i+3].second;
    }
    printf("%d\n",sum);
    sort(a,a+5);
    for(int i=0;i<5;i++) printf("%d ",a[i].first);
}