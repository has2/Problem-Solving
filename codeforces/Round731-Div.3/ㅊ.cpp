#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int tc;
int k,n,m,a[301],b[301];
 
void prt(){
    puts("a");
    for(int i=0;i<n;i++) printf("%d ",a[i]);
 
    puts("b");
    for(int i=0;i<m;i++) printf("%d ",b[i]);
}
 
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d%d",&k,&n,&m);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<m;i++) scanf("%d",&b[i]);
        vector<int> ans;
 
        int aidx=0,bidx=0;
        int it=m+n;
        while(it--){
            if(aidx<n){
                if(a[aidx]==0) {
                    k++;
                    aidx++;
                    ans.push_back(0);
                    continue;
                }
            }
            if(bidx<m){
                if(b[bidx]==0) {
                    k++;
                    bidx++;
                    ans.push_back(0);
                    continue;
                }
            }
 
            if(aidx<n){               
                if(k>=a[aidx]){
                    ans.push_back(a[aidx]);
                    aidx++;
 
                    continue;
                }
            }            
            if(bidx<m){
                if(k>=b[bidx]){
                    ans.push_back(b[bidx]);
                    bidx++;
                    continue;
                }
            }    
        }
        if(ans.size()<m+n) puts("-1");
        else{
            for(int a : ans) printf("%d ",a);
            puts("");
        }
    }
    
}