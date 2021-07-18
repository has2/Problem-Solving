#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int tc,n,a,b;
int main(){
    cin >> tc;
    while(tc--){
        string s;
        cin >> n >> a >> b >> s;
        int ans = n*a;
        if(b>0){
            ans+=b*n;
        }else if(b<0){
            
            int l=0;
            while(1){
                bool ok=1;
                int sidx=-1,eidx=-1;
                for(int i=1;i<s.size();i++){
                    if(s[i]!=s[i-1]){
                        sidx=i;
                        eidx=i;
                        ok=0;
                        for(int j=i+1;j<s.size()&&s[j]==s[i];j++){
                            eidx=j;
                        }
                        break;
                    }
                }
                if(ok) {
                    if(!s.empty()) l++;
                    break;
                }
                l++;
                s.erase(sidx,eidx-sidx+1);
            }
 
            ans+=l*b;
        }
        printf("%d\n",ans);
    }
}