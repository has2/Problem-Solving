#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

map<string,string> table;

vector<string> split(string s,string splitter){
    vector<string> ret;
    s+=splitter;
    int idx;
    while((idx=s.find(splitter)) != string::npos){
        string tmp = s.substr(0,idx);
        ret.push_back(tmp);
        //cout << tmp << '\n';
        s=s.substr(idx+splitter.size());
    }    
    return ret;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    table["cpp"]="1",table["java"]="2",table["python"]="3";
    table["backend"]="1",table["frontend"]="2";
    table["junior"]="1",table["senior"]="2";
    table["chicken"]="1",table["pizza"]="2";
    
    map<string,vector<int>> mp;
    for(auto s : info) {
        auto v = split(s," ");
        string hash;
        for(int i=0;i<v.size()-1;i++){
            hash+=table[v[i]];
        }
        mp[hash].push_back(stoi(v.back()));
    }
    for(auto& p : mp){
        sort(p.second.begin(),p.second.end());
    }
    
    int qnum=0;
    for(auto q : query){
        vector<string> sq = split(q," and ");
        vector<string> b = split(sq.back()," ");
        sq.pop_back();
        sq.insert(sq.end(),b.begin(),b.end());
        
        vector<string> v[4];
        
        for(int i=0;i<4;i++){
            if(sq[i]!="-") v[i] = {table[sq[i]]};
            else {
                v[i] = {"1","2"};
                if(i==0) v[i].push_back("3");
            }
        }
            
        int cnt=0;
        for(auto c1 : v[0]){
            for(auto c2 : v[1]){
                for(auto c3 : v[2]){
                    for(auto c4: v[3]){
                        string key = c1+c2+c3+c4;
                        int target=stoi(sq[4]);
                        auto it = lower_bound(mp[key].begin(),mp[key].end(),target);
                        cnt+=mp[key].end()-it;
                    }
                }
            }
        }
        answer.push_back(cnt);
        
    }
    return answer;
}