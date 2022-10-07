#include <cstdio>
#include <algorithm>
using namespace std;
int N,a[11],v[11];
bool check(){
    for(int i=1;i<=N;i++){
        int cnt=0;
        for(int j=1;j<i;j++){
            if(v[j]>v[i]) cnt++;
        }
        if(a[v[i]] != cnt) return 0;
    }
    return 1;
}
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
        v[i]=i;
    }
    do{
    }while(!check() &&next_permutation(v+1,v+1+N));
    for(int i=1;i<=N;i++) printf("%d ",v[i]);
}