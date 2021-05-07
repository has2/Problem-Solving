#include <cstdio>
#include <iostream>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
string s;
int tc,N,check[26];
 
void solve(){
    if(N==1) {
        puts("1");
        return;
    }
    if(N==2) {
        puts("-1");
        return;
    }
 
    vector<int> v;
    for(int i=1;i<=N*N;i+=2) v.push_back(i);
    for(int i=2;i<=N*N;i+=2) v.push_back(i);
 
    int idx=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",v[idx++]);
        }
        puts("");
    }
}
 
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&N);
        solve();
    }
}