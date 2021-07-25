#include <cstdio>
#include <cmath>
#include <set>
using namespace std;
int n;
set<int> a[3];
int sol(){
    for(int i=1;i<=sqrt(n);i++){
        if(i*i==n) return 1;
        a[1].insert(i*i);
    }
    for(auto v1 : a[1]){
        for(auto v2 : a[1]){
            if(v1+v2==n) return 2;
            a[2].insert(v1+v2);
        }
    }    
    for(int i=1;i<3;i++){
        for(auto v : a[i]){
            if(a[2].find(n-v) != a[2].end()) return i+2;
        }
    }
    return 0;
}
int main(){
    scanf("%d",&n);
    printf("%d",sol());
}