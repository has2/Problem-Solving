#include <cstdio>
#include <algorithm>
using namespace std;
int N;
pair<int,int> a[1000000];
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d%d",&a[i].first,&a[i].second);
    
    sort(a,a+N); 
    int s=a[0].first,e=a[0].second;
    int d=0;
    for(int i=1;i<N;i++){
        if(a[i].first<=e) {
            if(e<a[i].second) e=a[i].second;
        }
        else {
            d+=e-s;
            s=a[i].first;
            e=a[i].second;
        } 
    }
    d+=e-s;
    printf("%d",d);
}