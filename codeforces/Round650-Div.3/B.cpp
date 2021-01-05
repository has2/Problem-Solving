#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
int tc,N,a[41];
int sol(){
    int cnt =0;
    for(int i=0;i<N;i++){
        if(a[i]%2==i%2) continue;
        bool ok = 0;
        for(int j=i+1;j<N;j++){
            if(i%2==a[j]%2 && j%2==a[i]%2){
                swap(a[i],a[j]);
                cnt++;
                ok=1;
                break;
            }
        }
        if(!ok) return -1;
    }
    return cnt;
}
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&N);
        for(int i=0;i<N;i++) scanf("%d",&a[i]);
        printf("%d\n",sol());
    }
}
