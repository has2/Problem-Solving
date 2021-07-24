#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int tc,n,a,b,cnt[26];
int main(){
    cin >> tc;
    while(tc--){
        string s;
        cin >> s;
        memset(cnt,0,sizeof(cnt));
 
        for(char c : s){
            cnt[c-'a']++;
        }
 
        int ans=0,remain=0;
        for(int i=0;i<26;i++){
            if(cnt[i]>=2) ans++;
            else if(cnt[i]==1) remain++;
        }
        printf("%d\n",ans+remain/2);
    }
}