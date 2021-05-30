#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
int T,N,K;
string cmd,s;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie();
    cin >> T;
    while(T--){
        cin >> cmd >> N >> s;
        vector<int> v;
        int prev=1;
        for(int i=1;i<s.size();i++){
            if(i-prev>0){
                if(s[i]==',' || s[i]==']'){
                    string t = s.substr(prev,i-prev);
                    v.push_back(stoi(t));
                    prev=i+1;
                }
            }
        }
        int l=0,r=N-1;
        bool rvs=0,err=0;
        for(auto& c : cmd){
            if(c=='R') rvs = !rvs;
            else{
                if(l>r) {
                    err=1;
                    break;
                }
                if(rvs==0) l++;
                else r--;
            }
        }
        if(err){
            cout << "error" << '\n';
            continue;
        }
        cout << '[';
        if(!rvs) {
            for(int i=l;i<=r;i++){
                cout << v[i];
                if(i!=r) cout << ',';
            }
        }else{
            for(int i=r;i>=l;i--){
                cout << v[i];
                if(i!=l) cout << ',';
            }            
        }
        cout << ']' << '\n';   
    }
}