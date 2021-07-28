#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <cstdio>
using namespace std;
map<string,int> mp;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for(auto& order : orders){
        sort(order.begin(),order.end());
        
        int sz = order.size();
        for(int i=0;i<(1<<sz);i++){
            
            vector<bool> flag(sz);
            string tmp;
            for(int j=0;j<sz;j++){
                if((i&(1<<j))>0) flag[j]=1;         
            }
            for(int j=0;j<sz;j++){
                if(flag[j]) tmp.push_back(order[j]);
            }
            if(tmp.size()>=2) {
                mp[tmp]++;
            }
        }
    }
    for(auto c : course){
        vector<pair<int,string>> v;
        for(auto& p : mp){
            if(p.first.size()==c && p.second>=2){
               v.push_back({-p.second,p.first});   
            }
        }
        if(v.empty()) continue;
        sort(v.begin(),v.end());
        
        int minV = v[0].first;
        for(auto& p : v){
            if(minV!=p.first) break;
            answer.push_back(p.second);
        }
    }
    sort(answer.begin(),answer.end());

    return answer;
}