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
 
bool solve(){
    char cur = s[0];
    memset(check,0,sizeof(check));
    check[cur-'A']=1;
    for(int i=1;i<s.size();i++){
        
        if(s[i]!=cur){
            cur=s[i];
            if(check[cur-'A']) return false;
            check[cur-'A']=1;
            
        }
    }
    return true;
}
int main(){
    scanf("%d",&tc);
    while(tc--){
        cin >> N >> s;
        puts(solve()?"YES":"NO");
    }
}