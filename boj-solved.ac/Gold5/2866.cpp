#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int r,c,k,mv;
string s[1000];
int main(){
    cin >> r >> c;
    for(int i=0;i<r;i++) cin >> s[i];
    vector<string> st(c);
    for(int j=0;j<c;j++)
        for(int i=r-1;i>=0;i--) st[j].push_back(s[i][j]);
        
    sort(st.begin(),st.end());
    for(int i=0;i<c-1;i++){
        int k=0;
        for(int j=0;j<r;j++){
            if(st[i][j]==st[i+1][j]) k++;
            else break;
        }
        mv=max(k,mv);
    }
    cout << r-mv-1;
}