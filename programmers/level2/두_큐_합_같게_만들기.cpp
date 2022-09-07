#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;
ll sum,sum2;
queue<int> q1,q2;
int N;
int solution(vector<int> a, vector<int> b) {
    for(int i=0;i<a.size();i++){
        sum+=a[i];
        sum2+=b[i];
        q1.push(a[i]);
        q2.push(b[i]);
    }

    if((sum+sum2)%2)return -1;
    ll t = (sum+sum2)/2;

    int i=0,j=0,ans=0,n=a.size()*3;
    while(n--){
        if(sum>t){
            ans++;
            int v = q1.front();
            sum-=v;
            q2.push(v);
            q1.pop();
        }else if(sum<t){
            ans++; 
            int v = q2.front();
            sum+=v;
            q1.push(v);
            q2.pop();            
        }else{
            return ans;
        }
    }
    return -1;
}