// boj 1102 : DP & Bitmask 
// 2017/07/20
// mcost를 for문 밖에다 선언해버려서 최솟값이 초기화가 안됨
// p와 cnt의 초기조건에 따른 예외처리
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 987654321;
int cost[16][16],n,p;
int cache[16][1 << 16];


int sol(int cnt, int on) {


	if (cnt == p) return 0;

	int& ret = cache[cnt][on];
	if (ret != -1) return ret;

	ret = INF;

	for (int i = 0; i < n; i++) {
		if (((1 << i) & on) == 0) {
			int mcost = INF;
			for (int j = 0; j < n; j++)
				if(i!=j && (on & (1<<j))!=0)
					mcost = min(mcost, cost[j][i]);
	
			int cand = mcost + sol(cnt + 1, on | (1 << i));
			ret = min(ret, cand);
		}
	}

	return ret;
}

int main() {

	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &cost[i][j]);
	
	int On = 0,cnt = 0;
	char tmp[17];

	scanf("%s", tmp);
	scanf("%d", &p);
	for (int i = 0; i < n; i++) 
		if (tmp[i] == 'Y') {
			On |= (1 << i);
			cnt++;
		}

	int ans;
	if ((cnt == 0 && p == 0) || cnt >= p)
		ans = 0;
	else if (p > 0 && cnt == 0)
		ans = -1;
	else
		ans = sol(cnt, On);

	printf("%d", ans);

}
