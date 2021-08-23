#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
map<string,map<string,int>> mp;
void split(string str){
    vector<string> ret;
    int idx;
    str+=' ';
    while((idx=str.find(' '))!=string::npos){
        ret.push_back(str.substr(0,idx));
        str=str.substr(idx+1);
    }
    map<string,int> m;
    for(int i=1;i<=5;i++){
        m[ret[i]]=6-i;
    }
    mp[ret[0]]=m;
}
string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    for(auto t : table) split(t);
    int mv=0;
    for(auto p : mp){
        auto job = p.first;
        auto tb = p.second;
        int v=0;

        for(int i=0;i<languages.size();i++) v+=preference[i]*tb[languages[i]];
        if(v>mv){
            answer = job;
            mv=v;
        }
    }
    return answer;
}