#include <stack>
#include <iostream>
#include <string>
using namespace std;
bool erase[1000001];
string a,b;
stack<pair<int,int>> s;
int main(){
    cin >> a >> b;
    if(b.size()==1){
        for(int i=0;i<a.size();i++) if(a[i]==b[0]) erase[i] = 1;
    }else{
        for(int i=0;i<a.size();i++){
            if(!s.empty() && b[s.top().second+1]==a[i]){
                s.push({i,s.top().second+1});
                if(s.top().second==b.size()-1) {
                    int sz = b.size();
                    while(sz--) {
                        erase[s.top().first] = 1;
                        s.pop();
                    }
                }
            }
            else if(a[i]==b[0]) s.push({i,0});   
            else while(!s.empty()) s.pop();
        }
    }
    string ret;
    for(int i=0;i<a.size();i++) if(!erase[i]) ret += a[i];
    if(ret=="") puts("FRULA"); 
    else cout << ret;
}