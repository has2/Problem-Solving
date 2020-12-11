#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int N;
pair<int,int> a[100000];
string s[100000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> a[i].first >> s[i]; 
        a[i].second=i;
    }
    sort(a,a+N);
    for(int i=0;i<N;i++) cout << a[i].first << ' ' << s[a[i].second] << '\n';
}