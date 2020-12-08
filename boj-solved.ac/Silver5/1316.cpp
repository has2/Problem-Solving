#include <string>
#include <iostream>
#include <cstring>
using namespace std;
int n,ans;
string s;
bool a[26];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--){
        cin >> s;
        bool ok = 1;
        memset(a,0,26);
        for(int i=1;i<s.size();i++){
            if(s[i-1]!=s[i]) {
                if(a[s[i]-'a']){
                    ok=0;
                    break;
                }
                a[s[i-1]-'a'] = 1;
            }
        }
        ans+=ok;
    }
    cout << ans;
}