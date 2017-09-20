//BOJ
//ID : 1182 // backtracking
//2017/09/17

#include <cstdio>

int n,s,arr[20],ret;

void sol(int cur,int sum) {

	if (cur >= n) {
		if (sum == s) ret++;
		return;
	}

	sol(cur + 1, sum + arr[cur]);
	sol(cur + 1, sum);
}

int main() {
	scanf("%d%d", &n,&s);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sol(0, 0);
	printf("%d", s == 0 ? ret - 1 : ret);
}