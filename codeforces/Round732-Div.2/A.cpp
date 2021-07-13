#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int tc,N,a[100],b[100],INF=987654321;
 
bool same(){
    for(int i=0;i<N;i++){
        if(a[i]!=b[i]) return false;
    }
    return true;
}
void prt(){
    for(int i=0;i<N;i++){
        printf("%d ",a[i]);
    }
    puts("");
}
void solve(){
 
    int it=100;
    vector<pair<int,int>> ans;
    while(it--){
 
        int minDiff=INF,minIdx=-1;
        int maxDiff=-INF,maxIdx=-1;
        bool ok=1;
        for(int i=0;i<N;i++){
            int d = a[i]-b[i];
            if(d!=0) ok=0;
            if(minDiff>d){
                minDiff=d;
                minIdx=i;
            }
            if(maxDiff<d){
                maxDiff=d;
                maxIdx=i;
            }
        }
        if(ok) break;
 
        a[minIdx]++;
        a[maxIdx]--;
        ans.push_back({maxIdx,minIdx});
    }
    if(same()){
        printf("%d\n",ans.size());
        for(auto p : ans){
            printf("%d %d\n",p.first+1,p.second+1);
        }
    }else{
        puts("-1");
    }
}
 
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&N);
        for(int i=0;i<N;i++) scanf("%d",&a[i]);
        for(int i=0;i<N;i++) scanf("%d",&b[i]);
        solve();
    }
}