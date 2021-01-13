#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
string a[1001];
int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    map<string,vector<string>> start;
    map<string,set<string>> end;
    int N;
    cin>>N;
    for(int i=N-1;i>=0;i--) cin>>a[i];
    for(int i=0;i<N-1;i++)
        for(int j=i+1;j<N;j++) start[a[i]].push_back(a[j]);
    
    for(int i=N-1;i>=0;i--) cin>>a[i];
    for(int i=0;i<N-1;i++)
        for(int j=i+1;j<N;j++) end[a[i]].insert(a[j]);
    
    int ans = 0;
    for(auto k : start){
        string n = k.first;
        for(auto e : k.second){
            if(end[n].find(e) == end[n].end()) {
                ans++;
                break;
            }
        }
    }
    cout << ans;
}
