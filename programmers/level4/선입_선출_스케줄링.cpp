#include <vector>
#include <cstdio>
using namespace std;
int solution(int n, vector<int> cores) {
    int lo=-1,hi=2e5,mid=0;
    while(lo+1<hi){
        mid = (lo+hi)/2;
        int cnt=cores.size();
        if(mid>0) for(int i=0;i<cores.size();i++) cnt+=mid/cores[i];
        if(cnt<n) lo=mid;
        else hi=mid;
    }
    if(lo==-1) return n;
    int cnt=cores.size();
    for(int i=0;i<cores.size();i++) cnt+=lo/cores[i];
    for(int i=0;i<cores.size();i++){
        if((lo+1)%cores[i]==0) cnt++;
        if(cnt==n) return i+1;
    }
    return 0;
}