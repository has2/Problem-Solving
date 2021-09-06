#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
struct P{
    int w,wl,b,c,idx;
};
P arr[1001];
bool cmp(const P& l,const P& r){
    if(l.w*r.wl > r.w*l.wl) return 1;
    else if(l.w*r.wl == r.w*l.wl) {
        if(l.b > r.b) return 1;
        else if(l.b==r.b) {
            if(l.c>r.c) return 1;
            else if(l.c==r.c){
                return l.idx < r.idx;
            }
        }
    }
    return 0;
}
vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    N=weights.size();
    for(int i=0;i<N;i++){
        int w=0,l=0,ww=0;
        for(int j=0;j<N;j++){
            if(head2head[i][j]=='W') {
                w++;
                if(weights[j]>weights[i]) ww++;
            }
            else if(head2head[i][j]=='L') l++;
        }
        arr[i]={w,w+l,ww,weights[i],i};
    }
    sort(arr,arr+N,cmp);
    for(int i=0;i<N;i++) answer.push_back(arr[i].idx+1);
    return answer;
}

// data class P(val w:Double,val ww:Int,val weight:Int,val idx:Int)
// class Solution {
//     fun solution(weights: IntArray, head2head: Array<String>): IntArray {
//         val N=weights.size
//         var arr = Array<P>(N){P(0.0,0,0,0)}
//         for(i in 0..N-1){
//             var w=0;
//             var l=0;
//             var ww=0
//             for(j in 0..N-1) {
//                 if(head2head[i][j]=='W'){
//                     w++
//                     if(weights[j]>weights[i]) ww++
//                 }
//                 else if(head2head[i][j]=='L') l++
//             }
//             var wl = 0.0
//             if(w+l!=0) wl = w.toDouble()/(w+l)
//             arr[i] = P(wl,ww,weights[i],i)
//         }
//         return arr.sortedBy { it.idx }.sortedBy { -it.weight }.sortedBy { -it.ww }.sortedBy{-it.w}.map{it.idx+1}.toIntArray()
//     }
// }
