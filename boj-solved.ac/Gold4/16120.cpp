#include <iostream>
#include <string>
using namespace std;
string s;
int main(){
    cin >> s;
    bool ok = 1;
    string ans;
    for(int i=0;i<s.size();i++){
        if(s[i]=='P'){
            if(ans.empty()) ans.push_back('P');
            else if(ans.back()=='A') ans.pop_back(),ans.pop_back();
            else ans.push_back('P');
        }else{
            if(ans.size()>=2 && ans.back()=='P'&&ans[ans.size()-2]=='P') ans.push_back('A');
            else {
                ok=0;
                break;
            }
        }
    }
    if(ans=="PPAP") ans="P";
    if(!ok || ans != "P") puts("NP");
    else puts("PPAP");
}
