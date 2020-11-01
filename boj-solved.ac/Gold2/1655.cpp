//gold2 1655
#include <cstdio>
#include <queue>
#include <functional>
#include <vector>
using namespace std;
int N,a;
int main(){
    scanf("%d",&N);
    priority_queue<int> maxH;
    priority_queue<int,vector<int>,greater<int>> minH;

    for(int i=0;i<N;i++){
       scanf("%d",&a);
       if(i==0) maxH.push(a);
       else{
           if(maxH.top() >= a){
               maxH.push(a);
               if(maxH.size() >minH.size()+1){
                   minH.push(maxH.top()); maxH.pop();
               }
               
           }else{
               minH.push(a);
               if(maxH.size() < minH.size()){
                   maxH.push(minH.top()); minH.pop();
               }
           }
       }
       printf("%d\n",maxH.top());
    }
}