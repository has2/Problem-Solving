//BOJ
//ID : 1633 // dp
//2017/09/28
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int cache[16][16][1001],i;
int white[1001], black[1001];

int sol(int rw, int rb,int cur) {

	if ((rw == 0 && rb == 0) || cur == i) return 0;

	int& ret = cache[rw][rb][cur];
	if (ret != -1) return ret;

	ret = sol(rw, rb, cur + 1);
	if(rw > 0) ret = max(ret, white[cur] + sol(rw - 1, rb, cur + 1));
	if(rb > 0) ret = max(ret, black[cur] + sol(rw , rb-1, cur + 1));

	return ret;
}

int main() {

	int a, b;
	while (scanf("%d %d", &a, &b) != EOF) {
		white[i] = a; black[i++] = b;
	}
	memset(cache, -1, sizeof(cache));

	printf("%d", sol(15, 15, 0));
}