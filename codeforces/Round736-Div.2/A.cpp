
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <map>
using namespace std;
using ll = long long;
 
int tc,P;
 
int sol(int p){
 
    for(int i=2;i<=sqrt(p);i++){
        if(p%i==0){
            return i;
        }
    }
    return 0;
}
 
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&P);
        printf("%d %d\n",sol(P-1),P-1);
    }
 
}