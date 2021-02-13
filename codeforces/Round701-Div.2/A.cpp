#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int tc,a,b;
 
int sol(int a,int b){
    int ret=0;
    while(a!=0){
        a/=b;
        ret++;
    }
    return ret;
}
 
int main(){
    scanf("%d",&tc);
    while(tc--){
        int ans=1e8;
 
        scanf("%d%d",&a,&b);
 
        int prev=1e8;
        for(int i=0;;i++){
            if(b+i==1) continue;
 
            int t = sol(a,b+i);
            t+=i;
            if(t>prev) break;
            prev=t;
        }
        printf("%d\n",prev);
    }
}