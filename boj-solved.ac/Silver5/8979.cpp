#include <algorithm>
#include <cstdio>
struct P{
    int a,b,c,r;
};
bool cmp(P& u,P& v){
    if(u.a>v.a) return 1;
    else if(u.a==v.a) {
        if(u.b>v.b) return 1;
        else if(u.b==v.b) return u.c > v.c;
        return 0;
    }
    return 0;
}
int N,K;
P v[1001];
int main(){
    scanf("%d%d",&N,&K);    
    for(int i=0;i<N;i++) scanf("%d%d%d%d",&v[i].r,&v[i].a,&v[i].b,&v[i].c);
    
    std::sort(v,v+N,cmp);
    int r=0,pa=-1,pb=-1,pc=-1;
    for(int i=0;i<N;i++){
        if(v[i].a!=pa || v[i].b!=pb || v[i].c!=pc) {
            pa=v[i].a,pb=v[i].b,pc=v[i].c;
            r=i+1;
        }
        if(v[i].r==K) {
            printf("%d",r);
            break;
        }
    }
}