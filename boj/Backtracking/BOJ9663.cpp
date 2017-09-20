//BOJ
//ID : 9663 // backtracking
//2017/09/18

#include <cstdio>
#include <cmath>
int n,map[15],ret;

void sol(int cur,int pos) {

	for (int i = 0; i < cur; i++) 
		if (map[i] == pos || std::abs(pos - map[i]) == std::abs(cur - i)) return;
	
	if (cur == n-1) {
		ret++;
		return;
	}
	if(cur > -1) map[cur] = pos;
	for (int i = 0; i < n; i++) {
		sol(cur + 1, i);
	}
}

int main() {
	
	scanf("%d", &n);
	sol(-1, 0);
	printf("%d", ret);
}