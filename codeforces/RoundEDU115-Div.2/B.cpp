#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
int t,n,a[1000][5];
 
bool check(int u,int v){
    int f1=0,f2=0,f12=0;
 
    for(int i=0;i<n;i++){
        if(a[i][u] && a[i][v]) f12++;
        else if(a[i][u]) f1++;
        else if(a[i][v]) f2++;
    }
    if(f1+f2+f12!=n) return false;
 
    if(f1>f2) swap(f1,f2);
    f12-=f2-f1;
 
    if(f12<0) return false;
 
    if(f12%2) return false; 
 
    return true;
}
bool sol(){
    for(int i=0;i<4;i++){
        for(int j=i+1;j<5;j++){
            if(check(i,j)) return true;
        }
    }
    return false;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++) scanf("%d",&a[i][j]);
        }
        puts(sol()?"YES":"NO");
 
    }
}