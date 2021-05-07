
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
 
 
int mk(int sz,int num){
    int ret = num;
 
    for(int i=1;i<sz;i++) {
        ret*=10;
        ret+=num;
    }
    return ret;
}
 
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&N);
        int ans =0;
        string cvt = to_string(N);
        int sz = cvt.size();
 
        for(int i=1;i<sz;i++) ans+=9;
 
        for(int i=1;i<10;i++){
            int k = mk(sz,i);
            if(N<k) break;
            ans++;
        }
        printf("%d\n",ans);
    }
}