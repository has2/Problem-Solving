#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
using namespace std;
using ll = long long;
 
int t,N,a[51];
 
int solve(){
    bool ok=1;
    for(int i=1;i<=N;i++){
        if(a[i]!=i){
            ok=0;
            break;
        }
    }
    if(ok) return 0;
    
    if(a[1]==1 || a[N]==N) return 1;
    if(a[1]==N && a[N]==1) return 3;
 
    return 2;
}
 
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&N);
        for(int i=1;i<=N;i++) scanf("%d",&a[i]);
        printf("%d\n",solve());
    }
}