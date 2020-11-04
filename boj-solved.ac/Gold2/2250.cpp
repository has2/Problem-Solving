#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct Node{
    int left,right,h,x;
    Node(){}
    Node(int l,int r):left(l),right(r){}
};
int N,maxh,ans,ah,root,pos;
bool in[10001];
vector<Node> tree;
void sol(int n,int h){
    if(n==-1) return;
    sol(tree[n].left,h+1);
    tree[n].x=pos++;
    tree[n].h=h;
    maxh = max(maxh,h);
    sol(tree[n].right,h+1);
}

int main(){
    scanf("%d",&N);
    tree.resize(N+1);
    for(int i=1;i<=N;i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        tree[a] = Node(b,c);
        if(b!=-1) in[b] = 1;
        if(c!=-1) in[c] = 1;
    }
    for(int i=1;i<=N;i++) if(!in[i]) root = i;
    sol(root,1);
    for(int i=1;i<=maxh;i++){
        vector<int> slv;
        for(int j=1;j<=N;j++){
            if(tree[j].h==i) slv.push_back(j);
        }
        int len = 0;
        if(slv.size()==1) len = 1;
        else{
            for(int j=0;j<slv.size()-1;j++) 
                for(int k=j+1;k<slv.size();k++) 
                    len = max(len,abs(tree[slv[j]].x-tree[slv[k]].x)+1);
        }
        if(ans < len){
            ah = i;
            ans = len;
        }
    }
    printf("%d %d",ah,ans);
}

// #include <cstdio>
// #include <vector>
// #include <algorithm>
// using namespace std;
// struct Node{
//     int left,right,h=0,lcnt=0,rcnt=0,from,to;
//     Node(){}
//     Node(int l,int r):left(l),right(r){}
// };
// int N,maxh,ans,ah,root;
// bool in[10001];
// vector<Node> tree;
// int sol(int node,int h){
//     if(node==-1) return 0;
//     tree[node].h=h;
//     if(h>maxh) maxh=h;
//     tree[node].lcnt = sol(tree[node].left,h+1);
//     tree[node].rcnt = sol(tree[node].right,h+1);
//     return tree[node].lcnt+tree[node].rcnt+1;
// }

// void setPos(int node,int f,int t){
//     if(node==-1) return;
//     tree[node].from = f;
//     tree[node].to = t;
//     setPos(tree[node].left,f,f+tree[node].lcnt+1);
//     setPos(tree[node].right,f+tree[node].lcnt+1,t);
// }

// int main(){
//     scanf("%d",&N);
//     tree.resize(N+1);
//     for(int i=1;i<=N;i++) {
//         int a,b,c;
//         scanf("%d%d%d",&a,&b,&c);
//         tree[a] = Node(b,c);
//         if(b!=-1) in[b] = 1;
//         if(c!=-1) in[c] = 1;
//     }
//     for(int i=1;i<=N;i++) if(!in[i]) root = i;
    
//     sol(root,0);
//     setPos(root,0,N+1);
//     for(int i=0;i<=maxh;i++){
//         vector<int> slv;
//         for(int j=1;j<=N;j++){
//             if(tree[j].h==i) slv.push_back(j);
//         }
//         int len=0;
//         Node ll,rr;
//         if(slv.size()==1) len=1;
//         else {
//             for(int j=0;j<slv.size()-1;j++)
//                 for(int k=j+1;k<slv.size();k++) {
//                     ll = tree[slv[j]];
//                     rr = tree[slv[k]];
//                     if(ll.from+ll.lcnt >rr.from+rr.lcnt) swap(ll,rr);
//                     len = max(len,N-(ll.from+ll.lcnt+N-rr.to+1+rr.rcnt));
//                 }
//         }
//         if(ans < len){
//             ans = len;
//             ah = i;
//         }
//     }
//     printf("%d %d",ah+1,ans);
// }