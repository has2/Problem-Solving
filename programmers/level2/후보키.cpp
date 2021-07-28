#include <string>
#include <vector>
#include <cstdio>
#include <set>
using namespace std;
int N;
vector<int> bitmasks[9],cand;
vector<vector<string>> relation;
bool check(int bitmask){
    set<string> s;
    vector<int> flag(9);
    for(int i=0;i<N;i++){
        if(bitmask&(1<<i)) flag[i]=1;
    }
    for(auto rel : relation){
        string tmp;
        for(int i=0;i<N;i++){
            if(flag[i]) tmp+=(rel[i]+"#");
        }
        if(s.find(tmp)!=s.end()) return false;
        s.insert(tmp);
    }
    return true;
}
bool isExist(int bm){
    for(auto v : cand){
        if(v == (v&bm)) return true;   
    }
    return false;
}
int solution(vector<vector<string>> _relation) {
    relation=_relation;
    int answer = 0;
    N=relation[0].size();
    
    for(int i=1;i<(1<<N);i++){
        int cnt=0;
        for(int j=0;j<N;j++){
            if((i&(1<<j))>0) cnt++;
        }
        bitmasks[cnt].push_back(i);
    }
    for(int i=1;i<=N;i++){
        for(auto bm : bitmasks[i]){
            if(!isExist(bm)){
                if(check(bm)) {
                    cand.push_back(bm);
                    answer++;
                }
            }
        }
    }
    return answer;
}