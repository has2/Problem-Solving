#include <string>
#include <iostream>
using namespace std;
int tc;
int main(){
    cin >> tc;
    while(tc--){
        string s;
        cin >> s;
        cout << s[0];
        for(int i=1;i<s.size()-1;i+=2) cout << s[i];
        cout << s.back();
        puts("");
    }
}
