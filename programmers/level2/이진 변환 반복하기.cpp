#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;
using ll = long long;
vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(auto num : numbers){
        ll ret=0;
        int sz = log(num)/log(2)+2;
        if(num==0) sz=1;
        int idx;
        for(int i=0;i<sz;i++){
            if((num&(1LL<<i))==0) {
                idx=i;
                break;
            }
        }
        ret=num+(1LL<<(idx));
        if(idx>0) ret-=1LL<<(idx-1);
        answer.push_back(ret);
    }
    return answer;
}