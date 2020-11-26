#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using vvi = vector<vector<int>>;
int r,c,k;

vvi rot(vvi& m){
    int csz = m.size();
    int rsz = m[0].size();
    vector<vector<int>> ret(rsz,vector<int>(csz));
    for(int i=0;i<rsz;i++)
        for(int j=0;j<csz;j++) ret[i][j] = m[j][rsz-i-1];

    return ret;
}

vvi R(vvi& m){
    vvi tmp;
    int mxl = 0;
    for(auto v : m){
        map<int,int> cntMap;
        for(auto i : v) {
            if(i!=0) cntMap[i]++;
        }

        vector<pair<int,int>> ov;
        for(auto p : cntMap){
            ov.push_back({p.second,p.first});
        }
        sort(ov.begin(),ov.end());
        vector<int> res;
        for(auto o : ov){
            res.push_back(o.second);
            res.push_back(o.first);
        }
        mxl = max(mxl,(int)res.size());
        tmp.push_back(res);
    }
    mxl = min(100,mxl);
    for(auto& t : tmp) t.resize(mxl);
    return tmp;
}

int main(){
    scanf("%d%d%d",&r,&c,&k);
    r--,c--;
    vvi map;
    for(int i=0;i<3;i++){
        vector<int> a(3);
        for(int j=0;j<3;j++) scanf("%d",&a[j]);
        map.push_back(a);
    }
    int time = 0;
    while(1){
        int rsz = map.size();
        int csz = map[0].size();
        if(r < rsz && c < csz && map[r][c]==k) break;
        if(time==100){
            time = -1;
            break;
        }
        if(rsz >= csz){
            map = R(map);
        }else{
            map = rot(map);
            map = R(map);
            for(int i=0;i<3;i++) map=rot(map);
        }
        time++;
    }
    printf("%d",time);
}