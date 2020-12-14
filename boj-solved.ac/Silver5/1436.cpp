#include <cstdio>
#include <string>
using namespace std;
int N,cnt;
int main(){
    scanf("%d",&N);
    for(int i=666;;i++){
        string s = to_string(i);
        if(s.find("666") != string::npos) {
            if(++cnt==N) {
                printf("%s",s.c_str());
                break;
            }
        }
    }
}