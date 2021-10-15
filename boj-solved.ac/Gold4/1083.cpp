#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int N,a[50],S;
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    scanf("%d",&S);
    for(int i=0;i<N;i++){
        priority_queue<pair<int,int>> pq;
        for(int j=i;j<N;j++) pq.push({a[j],j-i});
        while(!pq.empty()){
            auto [v,dist] = pq.top(); pq.pop();
            if(dist<=S){
                int tmp=v;
                for(int j=i+dist-1;j>=i;j--) a[j+1]=a[j];
                a[i]=tmp;
                S-=dist;
                break;
            }
        }
        if(S==0) break;
    }
    for(int i=0;i<N;i++) printf("%d ",a[i]);
}