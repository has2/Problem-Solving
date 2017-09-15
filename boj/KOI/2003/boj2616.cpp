//BOJ
//ID : 2616 / DP
//2017/09/10

#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAX = 50000;
int n,k,tmp[MAX+1], cache[4][MAX+1],train[MAX+1];

int sol(int cnt, int num) {

	if (cnt == 3) return 0;
	if (num > n - k + 1) return 0;

	int& ret = cache[cnt][num];
	if (ret != -1) return ret;
	
	ret = std::max(sol(cnt,num+1), train[num+1]+sol(cnt + 1,num+k));
	
	return ret;

}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &tmp[i]);
	scanf("%d", &k);

	for (int i = 1; i <= n - k+1; i++) {
		int sum = 0;
		for (int j = 0; j < k; j++) sum += tmp[i + j];
		train[i] = sum;
	}
	memset(cache, -1, sizeof(cache));
	printf("%d", sol(0, 0));
}



