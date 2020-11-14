#include <cstdio>
using namespace std;
int ans,a[42][2],m[10],s[4],sd[4];
void sol(int cur,int cnt){
    if(cnt > ans) ans = cnt;
    if(cur==10) return;
    for(int i=0;i<4;i++){
        int p = s[i], d = sd[i],it=m[cur];
    
        if(p&&!(p%10)) {
            if(p==30 && d==0){
                p=28;
                it--;
            }
            d = 1;
        }
        
        for(int j=0;j<it && p!=-1;j++) p = a[p][d];
        if(p!=-1){
            bool ok = 0;
            for(int k=0;k<4;k++){
                if(i!=k && p==s[k] && (p==40 || d==sd[k])){
                    ok = 1;
                    break;
                }
            }
            if(ok) continue;
        }
        int org = s[i],orgd =sd[i];
        s[i] = p, sd[i] = d;
        sol(cur+1,cnt+(p==-1 ? 0 : p));
        s[i] = org, sd[i] = orgd;
    }
}
int main(){
    a[40][0] = a[40][1] = -1;
    for(int i=0;i<=38;i+=2) a[i][0] = i+2;
    for(int i=10;i<=16;i+=3) a[i][1] = i+3;
    a[19][1] = 25; a[30][1] = 28;
    for(int i=20;i<=22;i+=2) a[i][1] = i+2;
    a[24][1] = 25;
    for(int i=28;i>=26;i--) a[i][1] = i-1;
    for(int i=25;i<=35;i+=5) a[i][1] = i+5;

    for(int i=0;i<10;i++) scanf("%d",&m[i]);
    sol(0,0);
    printf("%d",ans);
}
