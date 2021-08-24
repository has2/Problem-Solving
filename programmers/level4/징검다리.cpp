#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(),rocks.end());
    int lo=0, hi=distance+1;
    while(lo+1<hi){
        int mid=(lo+hi)/2;
        int cnt=0;
        int cur=0;
        for(int i=0;i<rocks.size();i++){
            if(rocks[i]-cur>=mid) {
                cnt++;
                cur=rocks[i];
            }
        }
        if(cnt>=rocks.size()-n) lo=mid;
        else hi=mid;
    }
    return lo;
}