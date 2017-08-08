//BOJ
//ID : 1965 / LIS
//2017/07/25
#include <cstdio>
#include <cstring>
#include <algorithm>

int n,cache[1001],box[1001];

int sol(int start) {

	int& ret = cache[start];
	if (ret != -1) return ret;

	ret = 1;
	for (int i = start + 1; i <= n; i++) {
		if (box[start] < box[i])
			ret = std::max(ret, sol(i) + 1);
	}
	return ret;

}


int main() {

	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &box[i]);

	printf("%d", sol(0)-1);
}