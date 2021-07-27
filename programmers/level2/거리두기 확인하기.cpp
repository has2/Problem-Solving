#include <string>
#include <vector>
#include <cstdio>
using namespace std;


bool inRange(int y,int x){
    return (y<5 && x<5 && y>=0 && x>=0);
}

bool check(int y,int x,vector<string>& map){
    
    if(map[y][x]!='P') return true;
    
    if(inRange(y+1,x) && map[y+1][x]=='P') return false;
    
    if(inRange(y,x+1) && map[y][x+1]=='P') return false;
    
    if(inRange(y+2,x) && map[y+2][x]=='P' && map[y+1][x]!='X') return false;
    
    if(inRange(y,x+2) && map[y][x+2]=='P' && map[y][x+1]!='X') return false;
    
    
    if(inRange(y+1,x+1) && map[y+1][x+1]=='P'){
        if(map[y+1][x]!='X') return false;
        if(map[y][x+1]!='X') return false;
    }
    if(inRange(y+1,x-1) && map[y+1][x-1]=='P'){
        if(map[y][x-1]!='X') return false;
        if(map[y+1][x]!='X') return false;        
    }
    return true;
}

bool checkMap(vector<string>& map){
    for(int y=0;y<5;y++){
        for(int x=0;x<5;x++){
                if(!check(y,x,map)) {
                    return false;
                }
        }
    }
    return true;
}


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i=0;i<5;i++){
        bool ret = checkMap(places[i]);
        if(!ret) answer.push_back(0);
        else answer.push_back(1);
    }
    

    return answer;
}