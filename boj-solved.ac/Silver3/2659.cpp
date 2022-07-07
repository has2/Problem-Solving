#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int a[4];
string check(string o){
    vector<string> v;
    for(int i=0;i<4;i++){
        string s;
        for(int j=0;j<4;j++){
            s+=o[(i+j)%4];
        }
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    return v[0];
}
int main(){
    for(int i=0;i<4;i++) scanf("%d",&a[i]);
    vector<string> v;
    for(int i=0;i<4;i++){
        string s;
        for(int j=0;j<4;j++){
            s+=to_string(a[(i+j)%4]);
        }
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    int ans=1;
    for(int i=1111;;i++){
        string s = to_string(i);
        if(s.find("0") != string::npos) continue;
        if(check(s)!=s) continue;
        if(s==v[0]) break;
        ans++;
    }
    printf("%d",ans);
}
