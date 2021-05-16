#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
using namespace std;
using ll = long long;
 
int t,k;
 
int gcd(int a,int b){
    if(a>b) swap(a,b);
 
    while(a>0){
        int c = b%a;
        b=a;
        a=c;
    }
 
    return b;
}
 
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&k);
        if(k==100){
            puts("1");
            continue;
        }
 
        int a = k;
        int b = 100-k;
        int g = gcd(a,b);
        printf("%d\n",a/g+b/g);
    }
}