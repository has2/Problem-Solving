#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int tc;
int main(){
    cin >> tc;
    while(tc--){
        string s,ans;
        cin >> s;

        int cnt=0;
        do{
            ans = s;
            if(++cnt==2) break;
        }while(next_permutation(s.begin(),s.end()));
        cout << ans << '\n';
    }
}