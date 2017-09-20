//BOJ
//ID : 2602 // dp
//2017/09/19

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
string str, a[2];
int cache[101][21][2], slen, alen;

int sol(int cur, int scur, int loc) {
	
	if (scur == slen-1) return 1;

	int& ret = cache[cur][scur][loc];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = cur + 1; i < alen; i++) {
		if(str[scur+1] == a[1-loc][i]) ret += sol(i, scur + 1, 1 - loc);
	}
	return ret;
}

int main() {

	cin >> str >> a[0] >> a[1];
	slen = str.size();
	alen = a[0].size();
	memset(cache, -1, sizeof(cache));

	int res = 0;
	for (int i = 0; i < alen; i++) {
		if (a[0][i] == str[0]) res +=sol(i, 0, 0);
		if (a[1][i] == str[0]) res +=sol(i, 0, 1);
	}
	printf("%d",res);
}