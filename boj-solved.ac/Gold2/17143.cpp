#include <cstdio>
#include <vector>
using namespace std;
struct shark{
    int s,d,z;
};
using vvs = vector<vector<shark>>;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};
int R,C,M,ans;
int oppo(int d){
    return d%2 ? d-1 : d+1;
}
void move(vvs& cur,vvs& next){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            int s=cur[i][j].s, d=cur[i][j].d, z = cur[i][j].z;
            if(z==0 || s==0) {
                if(next[i][j].z < cur[i][j].z) next[i][j] = cur[i][j];
                continue;
            }
            int mv=s;
            if(d==0)mv+=R-1-i;
            else if(d==1) mv+=i;
            else if(d==2) mv+=j;
            else mv+=C-1-j;
            
            int k,r,div = d<2 ? R-1 : C-1;
            k = mv%div;
            r = mv/div;
            if(mv%div==0) {
                r--;
                k = div;
            }            
            pair<int,int> np;
            if(r%2==0) {
                if(d==0) np = {R-1-k,j}; 
                else if(d==1) np = {k,j};
                else if(d==2) np = {i,k};
                else np = {i,C-1-k};
            }else{
                if(d==0) np = {k,j};
                else if(d==1) np = {R-1-k,j};
                else if(d==2) np = {i,C-1-k};
                else np = {i,k};
                cur[i][j].d = oppo(cur[i][j].d);
            }
            if(next[np.first][np.second].z < cur[i][j].z) next[np.first][np.second] = cur[i][j];   
        }
    }
}
int main(){
    scanf("%d%d%d",&R,&C,&M);

    vvs map(R,vector<shark>(C));
    for(int i=0;i<M;i++){
        int r,c,s,d,z;
        scanf("%d%d%d%d%d",&r,&c,&s,&d,&z);
        map[r-1][c-1] = {s,d-1,z};
    }
    for(int i=0;i<C;i++){
        for(int j=0;j<R;j++){ 
            if(map[j][i].z!=0){
                ans += map[j][i].z;
                map[j][i].z=0;
                break;
            }
        }
        vvs next(R,vector<shark>(C));
        move(map,next);
        map = next;
    }
    printf("%d",ans);
}