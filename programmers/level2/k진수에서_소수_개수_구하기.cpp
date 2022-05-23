#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;
bool isPrime(ll v){
    if(v==1) return false;
    for(ll i=2;i<=sqrt(v);i++){
        if(v%i==0) return false;
    }
    return true;
}
int solution(int n, int k) {
    int answer = 0;
    string s;
    while(n/k>0){
        int m = n%k;
        s+=m+'0';
        n/=k;
    }
    s+=n+'0';
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        if(s[i]=='0') continue;
        string t;
        int j=i;
        for(;j<s.size()&&s[j]!='0';j++) t+=s[j];
        i=j;
        answer+=isPrime(stol(t));
    }
    return answer;
}