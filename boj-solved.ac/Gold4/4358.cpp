#include <iostream>
#include <map>
#include <string>
#include <cmath>
using namespace std;
map<string,int> m;
int n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    while(getline(cin,s)){
        m[s]++;
        n++;
    }
    for(auto k : m){
        double b = 100*k.second / (double)n;
        printf("%s %.4lf\n",k.first.c_str(),b);
    }
}