#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int tc,N;
string val[1001],cvt="0(){}[]";
string check(string a,string b){
    if(b=="-1") return a;
    if(a.size() < b.size()) return a;
    if(a.size() > b.size()) return b;
    return min(a,b);
}
void sol(){
    for(int i=1;i<=1000;i++) val[i]="-1";
    val[1]="12";
    val[2]="34";
    val[3]="56";
    for(int i=4;i<=1000;i++){
        string s;
        if(i%2==0) val[i]=check("1"+val[i/2]+"2",val[i]);
        if(i%3==0) val[i]=check("3"+val[i/3]+"4",val[i]);
        if(i%5==0) val[i]=check("5"+val[i/5]+"6",val[i]);
        for(int j=1;j<i;j++) {
            val[i] = check(val[i-j]+val[j],val[i]);
        }
    }
}
int main(){
    cin >> tc;
    sol();
    while(tc--){
        cin >> N;
        for(auto c : val[N]) {
            cout << cvt[c-'0'];
        }
        cout <<'\n';
    }
}