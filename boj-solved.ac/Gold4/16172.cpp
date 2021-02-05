#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string a,b,t;
int main(){
    cin >> t >> b;
    for(int i=0;i<t.size();i++){
        if(isalpha(t[i])) a.push_back(t[i]);
    }
    printf("%d",a.find(b) != string::npos);
}