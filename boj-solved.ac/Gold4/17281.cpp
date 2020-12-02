#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int N,a[50][9],res;
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        for(int j=0;j<9;j++) scanf("%d",&a[i][j]);
    
    vector<int> p = {1,2,3,4,5,6,7,8};
    do{
        vector<int> seq = p;
        seq.insert(seq.begin()+3,0);
        int scr = 0,j=0;
        for(int i=0;i<N;i++){
            vector<bool> pos(3);
            int out=0;
            while(out<3){
                int cmd = a[i][seq[j]];
                if(cmd==0) out++;
                else if(cmd<4){
                    for(int k=2;k>=0;k--){
                        if(pos[k]==1) {
                            int nxt = k+cmd;
                            if(nxt > 2) scr++;
                            else pos[nxt] = 1;
                            pos[k]=0;
                        }     
                    }
                    pos[cmd-1]=1;
                }else {
                    for(int k=2;k>=0;k--){
                        scr+=pos[k];
                        pos[k]=0;
                    }
                    scr++;
                }
                j=(j+1)%9;
            }
        }
        res = max(res,scr);
    }while(next_permutation(p.begin(),p.end()));
    printf("%d",res);
}